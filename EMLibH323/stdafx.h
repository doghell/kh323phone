
#pragma once


#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <ptlib.h>
#include <h323pluginmgr.h>
#include <ptlib/pprocess.h>
#include <ptclib/delaychan.h>
#include <ptlib/videoio.h>
#include <ptlib/vconvert.h>
#include <ptlib/video.h>
 
#include <h323.h>
#ifdef _DEBUG
#pragma comment(lib,"ptlibsd.lib")
#pragma comment(lib,"h323plusd.lib")
#else
#pragma comment(lib,"ptlibs.lib")
#pragma comment(lib,"h323plus.lib")
#endif

#include "EMLibH323.h"

class PluginLoaderStartup2 : public PProcessStartup
{
  PCLASSINFO(PluginLoaderStartup2, PProcessStartup);
  public:
    void OnStartup()
    { 
      // load the actual DLLs, which will also load the system plugins
      PStringArray dirs = PPluginManager::GetPluginDirs();
      PPluginManager & mgr = PPluginManager::GetPluginManager();
      PINDEX i;
      for (i = 0; i < dirs.GetSize(); i++) 
        mgr.LoadPluginDirectory(dirs[i]);

      // now load the plugin module managers
      PFactory<PPluginModuleManager>::KeyList_T keyList = PFactory<PPluginModuleManager>::GetKeyList();
      PFactory<PPluginModuleManager>::KeyList_T::const_iterator r;
      for (r = keyList.begin(); r != keyList.end(); ++r) {
        PPluginModuleManager * mgr = PFactory<PPluginModuleManager>::CreateInstance(*r);
        if (mgr == NULL) {
          PTRACE(1, "PLUGIN\tCannot create manager for plugins of type " << *r);
        } else {
          PTRACE(3, "PLUGIN\tCreated manager for plugins of type " << *r);
          managers.push_back(mgr);
        }
      }
    }

    void OnShutdown()
    {
      while (managers.begin() != managers.end()) {
        std::vector<PPluginModuleManager *>::iterator r = managers.begin();
        PPluginModuleManager * mgr = *r;
        managers.erase(r);
        mgr->OnShutdown();
      }
    }

  protected:
    std::vector<PPluginModuleManager *> managers;
};

class PWLibProcess : public PProcess 
{
	PCLASSINFO(PWLibProcess, PProcess);
	PWLibProcess():PProcess() { }
	void Main(){}
	static PluginLoaderStartup2 pluginLoader;
};

extern PWLibProcess pwlibProcess;