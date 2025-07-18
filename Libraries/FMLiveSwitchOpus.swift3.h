//
// Title: LiveSwitch Opus Extension for Cocoa
// Version: 0.0.0.0
// Copyright Frozen Mountain Software 2011+
//

#import <Foundation/Foundation.h>

#import "FMLiveSwitch.swift3.h"

@class FMLiveSwitchOpusNative;
@class FMLiveSwitchOpusExpertFrameDuration;
@class FMLiveSwitchOpusSignal;
@class FMLiveSwitchOpusBandwidth;
@class FMLiveSwitchOpusDecoder;
@class FMLiveSwitchOpusEncoder;
@class FMLiveSwitchOpusApplicationType;
@class FMLiveSwitchOpusEncoderConfig;
@class FMLiveSwitchOpusUtility;
/**

    Frame durations for Opus, used when updating the "OPUS_SET_EXPERT_FRAME_DURATION_REQUEST"
    (EncoderConfig.ExpertFrameDuration) configuration.

*/
@interface FMLiveSwitchOpusExpertFrameDuration : NSObject

/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_ARG".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) argument;
/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_10_MS".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) size10ms;
/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_2_5_MS".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) size2_5ms;
/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_20_MS".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) size20ms;
/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_40_MS".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) size40ms;
/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_5_MS".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) size5ms;
/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_60_MS".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) size60ms;
/**

    Gets the internal integer value representation of this frame duration.

*/
- (int) value;
/**

    Gets a frame duration of Opus "OPUS_FRAMESIZE_VARIABLE".

*/
+ (FMLiveSwitchOpusExpertFrameDuration*) variable;

@end

/**

    Signal types for Opus, used when updating the "OPUS_SET_SIGNAL_REQUEST" (EncoderConfig.Signal) configuration.

*/
@interface FMLiveSwitchOpusSignal : NSObject

/**

    Gets an signal type of Opus "OPUS_AUTO".

*/
+ (FMLiveSwitchOpusSignal*) auto;
/**

    Gets an signal type of Opus "OPUS_SIGNAL_MUSIC".

*/
+ (FMLiveSwitchOpusSignal*) music;
/**

    Gets the internal integer value representation of this signal.

*/
- (int) value;
/**

    Gets an signal type of Opus "OPUS_SIGNAL_VOICE".

*/
+ (FMLiveSwitchOpusSignal*) voice;

@end

/**

    Audio bandwidths for Opus, used when updating the "OPUS_SET_BANDWIDTH" (EncoderConfig.Bandwidth) or
    "OPUS_SET_MAX_BANDWIDTH" (EncoderConfig.MaxBandwidth) configuration.

*/
@interface FMLiveSwitchOpusBandwidth : NSObject

/**

    Gets a bandwidth of Opus "OPUS_AUTO".

*/
+ (FMLiveSwitchOpusBandwidth*) auto;
/**

    Gets a bandwidth of Opus "OPUS_BANDWIDTH_FULLBAND".

*/
+ (FMLiveSwitchOpusBandwidth*) fullBand;
/**

    Gets a bandwidth of Opus "OPUS_BANDWIDTH_MEDIUMBAND".

*/
+ (FMLiveSwitchOpusBandwidth*) mediumBand;
/**

    Gets a bandwidth of Opus "OPUS_BANDWIDTH_NARROWBAND".

*/
+ (FMLiveSwitchOpusBandwidth*) narrowBand;
/**

    Gets a bandwidth of Opus "OPUS_BANDWIDTH_SUPERWIDEBAND".

*/
+ (FMLiveSwitchOpusBandwidth*) superWideBand;
/**

    Gets the internal integer value representation of this signal.

*/
- (int) value;
/**

    Gets a bandwidth of Opus "OPUS_BANDWIDTH_WIDEBAND".

*/
+ (FMLiveSwitchOpusBandwidth*) wideBand;

@end

/**

    A libopus-based decoder.

*/
@interface FMLiveSwitchOpusDecoder : FMLiveSwitchAudioDecoder

/**

    Initializes a new instance of the FMLiveSwitchOpusDecoder class.

*/
+ (FMLiveSwitchOpusDecoder*) decoder;
/**

    Initializes a new instance of the FMLiveSwitchOpusDecoder class.

    @param config The configuration.
*/
+ (FMLiveSwitchOpusDecoder*) decoderWithConfig:(FMLiveSwitchAudioConfig*)config;
/**

    Initializes a new instance of the FMLiveSwitchOpusDecoder class.

    @param input The input.
*/
+ (FMLiveSwitchOpusDecoder*) decoderWithInput:(NSObject<FMLiveSwitchIAudioOutput>*)input;
/**

    Destroys this instance.

*/
- (void) doDestroy;
/**

    Processes a frame.

    @param frame The frame.
    @param inputBuffer The input buffer.
*/
- (void) doProcessFrame:(FMLiveSwitchAudioFrame*)frame inputBuffer:(FMLiveSwitchAudioBuffer*)inputBuffer;
/**

    Processes a SDP media description.

    @param mediaDescription The media description.
    @param isOffer if set to `true` [is offer].
    @param isLocalDescription if set to `true` [is local description].
*/
- (FMLiveSwitchError*) doProcessSdpMediaDescription:(FMLiveSwitchSdpMediaDescription*)mediaDescription isOffer:(bool)isOffer isLocalDescription:(bool)isLocalDescription;
/**

    Initializes a new instance of the FMLiveSwitchOpusDecoder class.

*/
- (instancetype) init;
/**

    Initializes a new instance of the FMLiveSwitchOpusDecoder class.

    @param config The configuration.
*/
- (instancetype) initWithConfig:(FMLiveSwitchAudioConfig*)config;
/**

    Initializes a new instance of the FMLiveSwitchOpusDecoder class.

    @param input The input.
*/
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIAudioOutput>*)input;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;

@end

/**

    A libopus-based encoder.

*/
@interface FMLiveSwitchOpusEncoder : FMLiveSwitchAudioEncoder

/**

    Gets a copy of the encoder codec's config.

*/
- (FMLiveSwitchOpusEncoderConfig*) codecConfig;
/**

    Gets a value indicating whether FEC is disabled.

*/
- (bool) disableFec;
/**

    Destroys this instance.

*/
- (void) doDestroy;
/**

    Processes the control frames.

    @param controlFrames The control frames.
*/
- (void) doProcessControlFrames:(NSMutableArray*)controlFrames;
/**

    Processes a frame.

    @param frame The frame.
    @param inputBuffer The input buffer.
*/
- (void) doProcessFrame:(FMLiveSwitchAudioFrame*)frame inputBuffer:(FMLiveSwitchAudioBuffer*)inputBuffer;
/**

    Processes a SDP media description.

    @param mediaDescription The media description.
    @param isOffer if set to `true` [is offer].
    @param isLocalDescription if set to `true` [is local description].
*/
- (FMLiveSwitchError*) doProcessSdpMediaDescription:(FMLiveSwitchSdpMediaDescription*)mediaDescription isOffer:(bool)isOffer isLocalDescription:(bool)isLocalDescription;
/**

    Initializes a new instance of the FMLiveSwitchOpusEncoder class.

*/
+ (FMLiveSwitchOpusEncoder*) encoder;
/**

    Initializes a new instance of the FMLiveSwitchOpusEncoder class.

    @param config The configuration.
*/
+ (FMLiveSwitchOpusEncoder*) encoderWithConfig:(FMLiveSwitchAudioConfig*)config;
/**

    Initializes a new instance of the FMLiveSwitchOpusEncoder class.

    @param input The input.
*/
+ (FMLiveSwitchOpusEncoder*) encoderWithInput:(NSObject<FMLiveSwitchIAudioOutput>*)input;
/**

    Initializes a new instance of the FMLiveSwitchOpusEncoder class.

*/
- (instancetype) init;
/**

    Initializes a new instance of the FMLiveSwitchOpusEncoder class.

    @param config The configuration.
*/
- (instancetype) initWithConfig:(FMLiveSwitchAudioConfig*)config;
/**

    Initializes a new instance of the FMLiveSwitchOpusEncoder class.

    @param input The input.
*/
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIAudioOutput>*)input;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;
/**

    Gets the loss percentage (0-100)
    before forward error correction (FEC) is
    activated (only if supported by the remote peer).
    Affects encoded data only.

*/
- (int) percentLossToTriggerFEC;
/**

    Gets the quality.

*/
- (double) quality;
/**

    Sets the encoder configuration.

    @return 0 on success, non-zero on failure.
*/
- (int) setCodecConfig:(FMLiveSwitchOpusEncoderConfig*)config;
/**

    Sets a value indicating whether FEC is disabled.

*/
- (void) setDisableFec:(bool)value;
/**

    Sets the loss percentage (0-100)
    before forward error correction (FEC) is
    activated (only if supported by the remote peer).
    Affects encoded data only.

*/
- (void) setPercentLossToTriggerFEC:(int)value;
/**

    Sets the quality.

*/
- (void) setQuality:(double)value;

@end

/**

    Application types for Opus, used when updating the "OPUS_SET_APPLICATION" (EncoderConfig.Application) configuration.

*/
@interface FMLiveSwitchOpusApplicationType : NSObject

/**

    Gets an application type of Opus "OPUS_APPLICATION_AUDIO".

*/
+ (FMLiveSwitchOpusApplicationType*) audio;
/**

    Gets an application type of Opus "OPUS_APPLICATION_RESTRICTED_LOWDELAY".

*/
+ (FMLiveSwitchOpusApplicationType*) restrictedLowDelay;
/**

    Gets the internal integer value representation of this application type.

*/
- (int) value;
/**

    Gets an application type of Opus "OPUS_APPLICATION_VOIP".

*/
+ (FMLiveSwitchOpusApplicationType*) voip;

@end

/**

    Configuration for the Opus encoder. Properties map to Opus controls.
    http://www.opus-codec.org/

*/
@interface FMLiveSwitchOpusEncoderConfig : NSObject

/**

    Gets a value that maps to "OPUS_SET_APPLICATION".

*/
- (FMLiveSwitchOpusApplicationType*) application;
/**

    Gets the integral value that maps to the Opus "OPUS_AUTO" constant. Several int configuration
    properties can be set to this value.

*/
+ (int) auto;
/**

    Gets a value that maps to "OPUS_SET_BANDWIDTH".

*/
- (FMLiveSwitchOpusBandwidth*) bandwidth;
/**

    Gets a value that maps to "OPUS_SET_COMPLEXITY".

*/
- (int) complexity;
/**

    Gets a deep copy of this configuration.

*/
- (FMLiveSwitchOpusEncoderConfig*) deepCopy;
/**

    Gets a value that maps to "OPUS_SET_DTX".

*/
- (int) dtx;
/**

    Creates a new copy of the Opus encoder configurations with default values.

*/
+ (FMLiveSwitchOpusEncoderConfig*) encoderConfig;
/**

    Gets a value that maps to "OPUS_SET_EXPERT_FRAME_DURATION".

*/
- (FMLiveSwitchOpusExpertFrameDuration*) expertFrameDuration;
/**

    Gets a value that maps to "OPUS_SET_FORCE_CHANNELS".

*/
- (int) forceChannels;
/**

    Gets a value that maps to "OPUS_SET_INBAND_FEC".

*/
- (bool) forwardErrorCorrection;
/**

    Creates a new copy of the Opus encoder configurations with default values.

*/
- (instancetype) init;
/**

    Gets a value that maps to "OPUS_SET_PREDICTION_DISABLED".

*/
- (bool) isPredictionDisabled;
/**

    Gets a value that maps to "OPUS_SET_VBR".

*/
- (bool) isVbr;
/**

    Gets a value that maps to "OPUS_SET_MAX_BANDWIDTH".

*/
- (FMLiveSwitchOpusBandwidth*) maxBandwidth;
/**

    Gets a value that maps to "OPUS_SET_PACKET_LOSS_PERC".

*/
- (int) packetLossPercent;
/**

    Sets a value that maps to "OPUS_SET_APPLICATION".

*/
- (void) setApplication:(FMLiveSwitchOpusApplicationType*)value;
/**

    Sets a value that maps to "OPUS_SET_BANDWIDTH".

*/
- (void) setBandwidth:(FMLiveSwitchOpusBandwidth*)value;
/**

    Sets a value that maps to "OPUS_SET_COMPLEXITY".

*/
- (void) setComplexity:(int)value;
/**

    Sets a value that maps to "OPUS_SET_DTX".

*/
- (void) setDtx:(int)value;
/**

    Sets a value that maps to "OPUS_SET_EXPERT_FRAME_DURATION".

*/
- (void) setExpertFrameDuration:(FMLiveSwitchOpusExpertFrameDuration*)value;
/**

    Sets a value that maps to "OPUS_SET_FORCE_CHANNELS".

*/
- (void) setForceChannels:(int)value;
/**

    Sets a value that maps to "OPUS_SET_INBAND_FEC".

*/
- (void) setForwardErrorCorrection:(bool)value;
/**

    Sets a value that maps to "OPUS_SET_PREDICTION_DISABLED".

*/
- (void) setIsPredictionDisabled:(bool)value;
/**

    Sets a value that maps to "OPUS_SET_VBR".

*/
- (void) setIsVbr:(bool)value;
/**

    Sets a value that maps to "OPUS_SET_MAX_BANDWIDTH".

*/
- (void) setMaxBandwidth:(FMLiveSwitchOpusBandwidth*)value;
/**

    Sets a value that maps to "OPUS_SET_PACKET_LOSS_PERC".

*/
- (void) setPacketLossPercent:(int)value;
/**

    Sets a value that maps to "OPUS_SET_SIGNAL".

*/
- (void) setSignal:(FMLiveSwitchOpusSignal*)value;
/**

    Sets a value that maps to "OPUS_SET_VBR_CONSTRAINT".

*/
- (void) setUseConstrainedVBR:(bool)value;
/**

    Gets a value that maps to "OPUS_SET_SIGNAL".

*/
- (FMLiveSwitchOpusSignal*) signal;
/**

    Gets a value that maps to "OPUS_SET_VBR_CONSTRAINT".

*/
- (bool) useConstrainedVBR;

@end

/**

    Opus-related utility functions.

*/
@interface FMLiveSwitchOpusUtility : NSObject

- (instancetype) init;
/**

    Initializes Opus native libraries.

*/
+ (bool) initialize;
+ (FMLiveSwitchOpusUtility*) utility;

@end

