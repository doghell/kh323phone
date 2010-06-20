/* myacm.h
 *
 * Microsoft G7231 codec for OpenH323/OPAL
 *
 * Copyright (c) 2005 ISVO (Asia) Pte Ltd. All Rights Reserved.
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
 * The Original Code is derived from and used in conjunction with the 
 * OpenH323/OPAL Project (www.openh323.org/)
 *
 * The Initial Developer of the Original Code is ISVO (Asia) Pte Ltd.
 *
 *
 * Contributor(s): ______________________________________.
 *
 *
*/

#include <codec/opalplugin.h>
#include<windows.h>


// Load the Library
#define MY_ACM_LIBRARY "myacmlib.lib"
#pragma comment(lib, MY_ACM_LIBRARY)

// All of PWLib/OpenH323 use MSVCRT.LIB or MSVCRTD.LIB, but EasyCodecs use
// libc.lib, so we need to tell the linker to ignore it, can't have two
// Run Time libraries!
#pragma comment(linker, "/NODEFAULTLIB:libc.lib")


#if _MSC_VER > 1000
#pragma once
#endif 

extern "C" {
   PLUGIN_CODEC_IMPLEMENT("ACM_G7231")
}


////////////////////////////////////////////////////////////////////////////
// Information

static struct PluginCodec_information licenseInfo = {
  1073619586,                              // timestamp = Fri 09 Jan 2004 03:39:46 AM UTC = 

  "Simon Horne	ISVO(Asia) Pte Ltd",                           // source code author
  "1.0",                                                       // source code version
  "shorne@isvo.net",		                                   // source code email
  "http://www.isvo.net",									   // source code URL
  "Copyright (C) 2005 by ISVO (Asia), All Rights Reserved",	   // source code copyright
  "MPL 1.0",                                                   // source code license
  PluginCodec_License_MPL,                                     // source code license

  "Microsoft ACM",                                               // codec description
  "Microsoft",												 // codec author
  NULL,                                                        // codec version
  NULL,                                                        // codec email
  "http://www.microsoft.com",                                // codec URL
  "Copyright (C) 2003-2004 Microsoft.com",					   // codec copyright information
  "NULL",                                                      // codec license
  PluginCodec_License_ResearchAndDevelopmentUseOnly            // codec license code
};

////////////////////////////////////////////////////////////////////////////
// Codec Information Template

#define DECLARE_PARAM(prefix) \
{ \
  /* encoder */ \
  PLUGIN_CODEC_VERSION_WIDEBAND,	  /* codec API version */ \
  &licenseInfo,                       /* license information */ \
  PluginCodec_MediaTypeAudio |        /* audio codec */ \
  PluginCodec_InputTypeRaw |          /* raw input data */ \
  PluginCodec_OutputTypeRaw |         /* raw output data */ \
  PluginCodec_RTPTypeExplicit,        /* dynamic RTP type */ \
  prefix##_Desc,                      /* text decription */ \
  prefix##_L16Desc,                   /* source format */ \
  prefix##_MediaFmt,                  /* destination format */ \
  (void*)Plugin_##prefix,			  /* user data */ \
  prefix##_SamplePerSec,              /* samples per second */ \
  prefix##_BitsPerSec,				  /* raw bits per second */ \
  prefix##_NsPerFrame,                /* nanoseconds per frame */ \
  prefix##_SamplesPerFrame,           /* samples per frame */ \
  prefix##_BytesPerFrame,			  /* bytes per frame */ \
  prefix##_RecFramesPerPacket,        /* recommended number of frames per packet */ \
  prefix##_MaxFramesPerPacket,        /* maximum number of frames per packet  */ \
  prefix##_IANACode,                  /* IANA RTP payload code */ \
  prefix##_IANAName,                  /* RTP payload name */ \
  create_encoder,                     /* create codec function */ \
  destroy_encoder,                    /* destroy codec */ \
  codec_encoder,                      /* encode/decode */ \
  NULL,                               /* codec controls */ \
  prefix##_CapType,					  /* h323CapabilityType */ \
  NULL								  /* h323CapabilityData */ \
}, \
{  \
  /* decoder */ \
  PLUGIN_CODEC_VERSION_WIDEBAND,	  /* codec API version */ \
  &licenseInfo,                       /* license information */ \
  PluginCodec_MediaTypeAudio |        /* audio codec */ \
  PluginCodec_InputTypeRaw |          /* raw input data */ \
  PluginCodec_OutputTypeRaw |         /* raw output data */ \
  PluginCodec_RTPTypeExplicit,         /* dynamic RTP type */ \
  prefix##_Desc,                      /* text decription */ \
  prefix##_MediaFmt,				  /* source format */ \
  prefix##_L16Desc,                   /* destination format */ \
  (void*)Plugin_##prefix,			  /* user data */ \
  prefix##_SamplePerSec,              /* samples per second */ \
  prefix##_BitsPerSec,				  /* raw bits per second */ \
  prefix##_NsPerFrame,                /* nanoseconds per frame */ \
  prefix##_SamplesPerFrame,           /* samples per frame */ \
  prefix##_BytesPerFrame,			  /* bytes per frame */ \
  prefix##_RecFramesPerPacket,        /* recommended number of frames per packet */ \
  prefix##_MaxFramesPerPacket,        /* maximum number of frames per packet  */ \
  prefix##_IANACode,                  /* IANA RTP payload code */ \
  prefix##_IANAName,                  /* RTP payload name */ \
  create_decoder,                     /* create codec function */ \
  destroy_decoder,                    /* destroy codec */ \
  codec_decoder,                      /* encode/decode */ \
  NULL,                               /* codec controls */ \
  prefix##_CapType,					  /* h323CapabilityType */ \
  NULL								  /* h323CapabilityData */ \
} \

//#define Microsoft ACM G7231
#define  Plugin_ACM_63  1
#define  L_G7231_FRAME_COMPRESSED_63 24
#define  L_G7231_FRAME               240

static const char		ACM_63_Desc[] = { "Microsoft ACM G7231-6.3" };	// text decription  
static const char		ACM_63_L16Desc[]= { "L16" };			// source format 
static const char		ACM_63_MediaFmt[] = { "G.7231-6.3k[m]" };	// destination format  
static unsigned int		ACM_63_SamplePerSec = 8000;          // samples per second  
static unsigned int		ACM_63_BitsPerSec = 6300;			// raw bits per second  
static unsigned int		ACM_63_NsPerFrame = 30000;			// nanoseconds per frame
static unsigned int		ACM_63_SamplesPerFrame = L_G7231_FRAME; // samples per frame 
static unsigned int		ACM_63_BytesPerFrame = L_G7231_FRAME_COMPRESSED_63; // Bytes per frame
static unsigned int		ACM_63_RecFramesPerPacket = 1;        //rec number of frames per packet 
static unsigned int		ACM_63_MaxFramesPerPacket = 1;       // max number of frames per packet
#define	ACM_63_IANACode  4									// IANA RTP payload code  
static const char		ACM_63_IANAName[] = { "G7231" };		// RTP payload name 
static unsigned char	ACM_63_CapType = PluginCodec_H323AudioCodec_g7231;	// h323CapabilityType 



