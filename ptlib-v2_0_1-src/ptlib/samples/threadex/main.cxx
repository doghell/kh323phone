/*
 * main.cxx
 *
 * PWLib application source file for threadex
 *
 * Main program entry point.
 *
 * Copyright (c) 2003 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Portable Windows Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: main.cxx,v $
 * Revision 1.13  2006/07/22 07:27:26  rjongbloed
 * Fixed various compilation issues
 *
 * Revision 1.12  2006/03/29 23:28:52  dereksmithies
 * Fix use of null pointer.
 *
 * Revision 1.11  2006/03/29 23:18:18  dereksmithies
 * Remove compiler warning about unused variable.
 *
 * Revision 1.10  2006/01/20 00:34:09  dereksmithies
 * Add PTRACE statements to the DelayThread Constructors and Destructor.
 *
 * Revision 1.9  2006/01/13 07:20:22  dereksmithies
 * add option to use threads generated by the PThread::Create call.
 *
 * Revision 1.8  2006/01/11 22:14:48  dereksmithies
 * Add autodelete test option to code.
 * Move Resume() operators out of the constructor for threads.
 * The Resume() operator is "ok" in the constructor, if Resume() is at the end of the constructor,
 * and the thread class does not have a descendant.
 *
 * Revision 1.7  2006/01/06 23:08:24  dereksmithies
 * Add some code, now it crashes on unix with the command args -d 1 -b
 *
 * Revision 1.6  2005/11/30 12:47:41  csoutheren
 * Removed tabs, reformatted some code, and changed tags for Doxygen
 *
 * Revision 1.5  2005/07/28 00:25:03  dereksmithies
 * Update console reading code so it works via a ssh connection to a remote machine.
 * Add D option to console, so report the average time taken by each iteration of the thread.
 *
 * Revision 1.4  2005/07/26 02:52:39  dereksmithies
 * Use different console handling code. Still get "console gone errors" when on
 * remote box.
 *
 * Revision 1.3  2005/07/26 01:43:05  dereksmithies
 * Set up so that only H or h or ? generate a help message.
 *
 * Revision 1.2  2005/07/26 00:46:22  dereksmithies
 * Commit code to provide two examples of waiting for a thread to terminate.
 * The busy wait method provides a method of testing PWLIB processes for closing
 * a thread. With a delay of 20ms, SMP box, we found some pwlib methods that
 * needed fixing. At the time of committing this change, the pwlib code was correct.
 *
 * Revision 1.1  2004/09/13 01:13:26  dereksmithies
 * Initial release of VERY simple program to test PThread::WaitForTermination
 *
 * Revision 1.3  2004/09/10 22:33:31  dereksmithies
 * Calculate time required to do the decoding of the dtmf symbol.
 *
 * Revision 1.2  2004/09/10 04:31:57  dereksmithies
 * Add code to calculate the detection rate.
 *
 * Revision 1.1  2004/09/10 01:59:35  dereksmithies
 * Initial release of program to test Dtmf creation and detection.
 *
 *
 */

#include "precompile.h"
#include "main.h"
#include "version.h"


PCREATE_PROCESS(Threadex);

#include  <ptclib/dtmf.h>
#include  <ptclib/random.h>



Threadex::Threadex()
  : PProcess("Derek Smithies code factory", "threadex", MAJOR_VERSION, MINOR_VERSION, BUILD_TYPE, BUILD_NUMBER)
{
}

/*Note: This program uses either a busy wait system to check for
   thread termination, or the WaitForTermination method supplied by
   pwlib. It was found that with sufficient number of iterations,
   busywaiting, and a delay of 20ms on a SMP machine that segfaults
   occurred. This program was used to verify the correct close down
   and creation process of a thread */

void Threadex::Main()
{
  PArgList & args = GetArguments();

  args.Parse(
	     "a-autodelete."         "-no-autodelete."
	     "c-create."             "-no-create."
             "h-help."               "-no-help."
             "d-delay:"              "-no-delay."
             "b-busywait."           "-no-busywait."
#if PTRACING
             "o-output:"             "-no-output."
             "t-trace."              "-no-trace."
#endif
             "v-version."
  );

#if PTRACING
  PTrace::Initialise(args.GetOptionCount('t'),
                     args.HasOption('o') ? (const char *)args.GetOptionString('o') : NULL,
         PTrace::Blocks | PTrace::Timestamp | PTrace::Thread | PTrace::FileAndLine);
#endif

  if (args.HasOption('v')) {
    cout << "Product Name: " << GetName() << endl
         << "Manufacturer: " << GetManufacturer() << endl
         << "Version     : " << GetVersion(TRUE) << endl
         << "System      : " << GetOSName() << '-'
         << GetOSHardware() << ' '
         << GetOSVersion() << endl;
    return;
  }

  if (args.HasOption('h')) {
    PError << "Available options are: " << endl         
           << "-h  or --help        :print this help" << endl
           << "-v  or --version      print version info" << endl
           << "-d  or --delay ##     where ## specifies how many milliseconds the created thread waits for" << endl
           << "-b  or --busywait     where if specified will cause the created thread to be tested for termination using a busy wait." << endl
	   << "-a  or --autodelete   where the pwlib methods for auto deleting a thread are used" << endl
           << "-c  or --create       Use the pwlib PThread::Create method to create a thread of the reqired type" << endl
#if PTRACING
           << "o-output              output file name for trace" << endl
           << "t-trace.              trace level to use." << endl
#endif
           << endl
           << endl << endl;
    return;
  }

  delay = 2000;
  if (args.HasOption('d'))
    delay = args.GetOptionString('d').AsInteger();

  delay = PMIN(1000000, PMAX(0, delay));
  cout << "Created thread will wait for " << delay << " milliseconds before ending" << endl;
 
  doBusyWait = args.HasOption('b');

  doAutoDelete = args.HasOption('a');

  doCreate = args.HasOption('c');

  UserInterfaceThread ui;
  ui.Resume();
  ui.WaitForTermination();
}

/////////////////////////////////////////////////////////////////////////////

DelayThread::DelayThread(PINDEX _delay)
  : PThread(10000, NoAutoDeleteThread), delay(_delay)
{
  PTRACE(5, "Constructor for a non auto deleted delay thread");
}    

DelayThread::DelayThread(PINDEX _delay, BOOL)
  : PThread(10000, AutoDeleteThread), delay(_delay)
{
  PTRACE(5, "Constructor for an auto deleted  delay thread");
}


DelayThread::~DelayThread()
{
  PTRACE(5, "Destructor for a delay thread");
  //This thread must not have a PTRACE statement in the debugger, if it is an autodeleted thread.
  //If a PTRACE statement is here, the PTRACE will fail as the PThread::Current() returns empty.
}

void DelayThread::Main()  
{
  PThread::Sleep(delay);
  PTRACE(5, "DelayThread\t all finished");
}

///////////////////////////////////////////////////////////////////////////

void LauncherThread::AutoCreatedMain(PThread &, INT param)
{
  PThread::Sleep(param);
}

void LauncherThread::Main()
{
  PINDEX delay = Threadex::Current().Delay();
  BOOL   doCreate = Threadex::Current().Create();

  PThread *thread = NULL;
  if (Threadex::Current().AutoDelete()) {
    while (keepGoing) {
      if (doCreate) {
	thread = PThread::Create(PCREATE_NOTIFIER(AutoCreatedMain), delay,
                                     PThread::AutoDeleteThread,
                                     PThread::NormalPriority,
                                     "auto deleted %X");
      } else {
	thread = new DelayThread(delay, TRUE);
	thread->Resume();
      }
      //     PThread::Sleep(1);
      iteration++;
    }
    return;
  }

  if (Threadex::Current().BusyWait()) {
    while (keepGoing) {
      if (doCreate) {
	thread = PThread::Create(PCREATE_NOTIFIER(AutoCreatedMain), delay,
				 PThread::NoAutoDeleteThread,
				 PThread::NormalPriority,
				 "auto BusyWaited %X");
      } else {
	thread = new DelayThread(delay);
	thread->Resume();
      }
      
      while (!thread->IsTerminated());
      delete thread;
      iteration++;
    }
    return;
  }

  while (keepGoing) {
    if (doCreate) {
      thread = PThread::Create(PCREATE_NOTIFIER(AutoCreatedMain), delay,
			       PThread::NoAutoDeleteThread,
			       PThread::NormalPriority,
			       "auto WaitForTermination %X");
    } else {
      thread = new DelayThread(delay);
      thread->Resume();
    }
    thread->WaitForTermination();
    delete thread;
    iteration++;
  }
}

void UserInterfaceThread::Main()
{
  PConsoleChannel console(PConsoleChannel::StandardInput);
  cout << "This program will repeatedly create and destroy a thread until terminated from the console" << endl;

  PStringStream help;
  help << "Press : " << endl
       << "         D      average Delay time of each thread" << endl
       << "         H or ? help"                              << endl
       << "         R      report count of threads done"      << endl
       << "         T      time elapsed"                      << endl
       << "         X or Q exit "                             << endl;
 
  cout << endl << help;

  LauncherThread launch;
  launch.Resume();

  console.SetReadTimeout(P_MAX_INDEX);
  for (;;) {
    int ch = console.ReadChar();

    switch (tolower(ch)) {
    case 'd' :
      {
        int i = launch.GetIteration();
        if (i == 0) {
          cout << "Have not completed an iteration yet, so time per iteration is unavailable" << endl;
        } else {
          cout << "Average time per iteration is " << (launch.GetElapsedTime().GetMilliSeconds()/((double) i)) 
               << " milliseconds" << endl;
        }
        cout << "Command ? " << flush;
        break;
      }
    case 'r' :
      cout << "\nHave completed " << launch.GetIteration() << " iterations" << endl;
      cout << "Command ? " << flush;
      break;
    case 't' :
      cout << "\nElapsed time is " << launch.GetElapsedTime() << " (Hours:mins:seconds.millseconds)" << endl;
      cout << "Command ? " << flush;
      break;

    case 'x' :
    case 'q' :
      cout << "Exiting." << endl;
      launch.Terminate();
      launch.WaitForTermination();
      return;
      break;
    case '?' :
    case 'h' :
      cout << help << endl;
      cout << "Command ? " << flush;
    default:
      break;
                                                                                                                                            
    } // end switch
  } // end for
}


// End of File ///////////////////////////////////////////////////////////////
