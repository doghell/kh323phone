/* 
 * myacm.cxx
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

#include "myacm.h"

extern "C" {
#include "myacmlib.h"
}

///////////////////////////////////////////////////////////////////////////////////////////////

static void * create_encoder(const struct PluginCodec_Definition * codec)
{
   acm_init_encoder_g7321();

  return (void *)1; 
}

static int codec_encoder(const struct PluginCodec_Definition * codec, 
                                           void * context,
                                     const void * from, 
                                       unsigned * fromLen,
                                           void * to,         
                                       unsigned * toLen,
                                   unsigned int * flag)
{


	if (*fromLen != codec->parm.audio.samplesPerFrame *2)
    return 0;

// session->easy->enc(session->hEcoder, (short *)from, (unsigned char *)to);
 
// Encode Speech into Bitstream
   acm_encoder((short *)from,  *fromLen,(unsigned char *)to, *toLen);


  *toLen   = codec->parm.audio.bytesPerFrame;

  return 1; 
}

static void destroy_encoder(const struct PluginCodec_Definition * codec, void * context)
{
   acm_close_encoder();
}

static void * create_decoder(const struct PluginCodec_Definition * codec)
{

		acm_init_decoder_g7321();

  return (void *)1; 
}

static int codec_decoder(const struct PluginCodec_Definition * codec, 
                                           void * context,
                                     const void * from, 
                                       unsigned * fromLen,
                                           void * to,         
                                       unsigned * toLen,
                                   unsigned int * flag)
{

  struct EasySession * session = (EasySession *)context;

  if (*fromLen !=  codec->parm.audio.bytesPerFrame)
    return 0;

//   session->easy->dec(session->hDcoder,(unsigned char *)from, (short *)to);
// Decodee Bitstream into syntesized Speech
  acm_decoder((unsigned char *)from, *fromLen, (short *)to, *toLen);

  *toLen   = codec->parm.audio.samplesPerFrame * 2;

  return 1; 
}

static void destroy_decoder(const struct PluginCodec_Definition * codec, void * context)
{

  acm_close_decoder();

}

///////////////////////////////////////////////////////////////////////////////////////////////

static struct PluginCodec_Definition CodecDefn[] = {
  DECLARE_PARAM(ACM_63)
};

#define NUM_DEFNS   (sizeof(CodecDefn) / sizeof(struct PluginCodec_Definition))


extern "C" {

PLUGIN_CODEC_DLL_API struct PluginCodec_Definition * PLUGIN_CODEC_GET_CODEC_FN(unsigned * count, unsigned version)
{
  *count = NUM_DEFNS;
  return CodecDefn;	
}

};

