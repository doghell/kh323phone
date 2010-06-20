//
// h46018.h
//
// Code automatically generated by asnparse.
//

#if ! H225_DISABLE_H46018

#ifndef __H46018_H
#define __H46018_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptclib/asner.h>

#include "h225.h"


//
// IncomingCallIndication
//

class H46018_IncomingCallIndication : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H46018_IncomingCallIndication, PASN_Sequence);
#endif
  public:
    H46018_IncomingCallIndication(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    H225_TransportAddress m_callSignallingAddress;
    H225_CallIdentifier m_callID;

    PINDEX GetDataLength() const;
    BOOL Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// LRQKeepAliveData
//

class H46018_LRQKeepAliveData : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H46018_LRQKeepAliveData, PASN_Sequence);
#endif
  public:
    H46018_LRQKeepAliveData(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    H225_TimeToLive m_lrqKeepAliveInterval;

    PINDEX GetDataLength() const;
    BOOL Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


#endif // __H46018_H

#endif // if ! H225_DISABLE_H46018


// End of h46018.h
