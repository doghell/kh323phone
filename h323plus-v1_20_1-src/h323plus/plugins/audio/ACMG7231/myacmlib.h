// #########################################################################
//                        MyACM Library header file
//
//           The Bridge for using MS Windows Audio Codecs Manager(ACM) 
//                 as the codecs source for OpenH323 project.
//
// Initial Developer: -=MaGGuS=-					2003
// #########################################################################

#define G7231_FRAME_MIN 3		// Minimal frame length for G.723.1 codec

// ########################### Encoder functions ###########################

// Unified ACM codec encoder initializer
BOOL acm_init_encoder(UINT SoundCodecTag, UINT CodedCodecTag, UINT SampleRate, UINT Channels, UINT BitsPerSample, UINT CodecMode=0);

// Sample G.723.1 encoder initializer
BOOL acm_init_encoder_g7321(UINT Type=2/*6k3 - default*/);

// Encode Speech into Bitstream
void acm_encoder(short *speech, unsigned spchLength, unsigned char *bitstream, unsigned & btstLength);

// Close and cleanup encoder
void acm_close_encoder();

// ########################### Decoder functions ###########################

// Unified ACM codec decoder initializer
BOOL acm_init_decoder( UINT CodedCodecTag, UINT SoundCodecTag, UINT SampleRate, UINT Channels, UINT BitsPerSample, UINT CodecMode=0);

// Sample G.723.1 decoder initializer
BOOL acm_init_decoder_g7321(UINT Type=2/*6k3 - default*/);

// Decodee Bitstream into syntesized Speech
void acm_decoder(unsigned char *bitstream, unsigned btstLength, short *synth_short, unsigned & btstUsed);

// Close and cleanup decoder
void acm_close_decoder();

// ################################## EOF ##################################