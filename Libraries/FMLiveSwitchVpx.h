//
// Title: LiveSwitch VPX Extension for Cocoa
// Version: 0.0.0.0
// Copyright Frozen Mountain Software 2011+
//

#import <Foundation/Foundation.h>

#import "FMLiveSwitch.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wnullability-completeness"

@class FMLiveSwitchVpxNative;
@class FMLiveSwitchVpxTemporalLayerMode;
@class FMLiveSwitchVpxCodecWrapper;
@class FMLiveSwitchVpxDecoder;
@class FMLiveSwitchVpxEncoder;
@class FMLiveSwitchVpxBitDepth;
@class FMLiveSwitchVpxEndUsageMode;
@class FMLiveSwitchVpxKeyframeMode;
@class FMLiveSwitchVpxEncoderConfig;
@class FMLiveSwitchVpxErrorResilientType;
@class FMLiveSwitchVpxUtility;
@class FMLiveSwitchVp8Decoder;
@class FMLiveSwitchVp8Encoder;
@class FMLiveSwitchVp9Decoder;
@class FMLiveSwitchVp9Encoder;
/**

    A libvpx-based codec.

*/
typedef NS_ENUM(NSInteger, FMLiveSwitchVpxCodec) {
    /**

        Indicates the VP8 codec.

    */
    FMLiveSwitchVpxCodecVp8 = 1,
    /**

        Indicates the VP9 codec.

    */
    FMLiveSwitchVpxCodecVp9 = 2
};

/**

    Temporal layer modes for VPX output.

*/
@interface FMLiveSwitchVpxTemporalLayerMode : NSObject

/**

    Gets a the temporal layering mode VP9E_TEMPORAL_LAYERING_MODE_BYPASS.

*/
+ (FMLiveSwitchVpxTemporalLayerMode*) bypass;
/**

    Gets a the temporal layering mode VP9E_TEMPORAL_LAYERING_MODE_0101.

*/
+ (FMLiveSwitchVpxTemporalLayerMode*) mode0101;
/**

    Gets a the temporal layering mode VP9E_TEMPORAL_LAYERING_MODE_0212.

*/
+ (FMLiveSwitchVpxTemporalLayerMode*) mode0212;
/**

    Gets a the temporal layering mode VP9E_TEMPORAL_LAYERING_MODE_NOLAYERING.

*/
+ (FMLiveSwitchVpxTemporalLayerMode*) noLayering;
/**

    Gets the internal integer value representation of this temporal layer mode.

*/
- (int) value;

@end

@interface FMLiveSwitchVpxCodecWrapper : NSObject

- (NSString*) description;
- (instancetype) initWithValue:(FMLiveSwitchVpxCodec)value;

@end

/**

    A libvpx-based decoder.

*/
@interface FMLiveSwitchVpxDecoder : FMLiveSwitchVideoDecoder

/**

    Gets the current codec.

*/
- (FMLiveSwitchVpxCodec) codec;
/**

    Initializes a new instance of the FMLiveSwitchVpxDecoder class.

    @param inputFormat The input format.
*/
+ (FMLiveSwitchVpxDecoder*) decoderWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat;
/**

    Destroys this instance.

*/
- (void) doDestroy;
/**

    Processes a frame.

    @param frame The frame.
    @param inputBuffer The input buffer.
*/
- (void) doProcessFrame:(FMLiveSwitchVideoFrame*)frame inputBuffer:(FMLiveSwitchVideoBuffer*)inputBuffer;
/**

    Initializes a new instance of the FMLiveSwitchVpxDecoder class.

    @param inputFormat The input format.
*/
- (instancetype) initWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat;
/**

    Gets a value indicating whether the decoder needs a keyframe.

*/
- (bool) needsKeyFrame;

@end

/**

    A libvpx-based encoder.

*/
@interface FMLiveSwitchVpxEncoder : FMLiveSwitchVideoEncoder

/**

    Gets the current codec.

*/
- (FMLiveSwitchVpxCodec) codec;
/**

    Gets the encoder configuration.

*/
- (FMLiveSwitchVpxEncoderConfig*) codecConfig;
/**

    Destroys this instance.

*/
- (void) doDestroy;
/**

    Processes a frame.

    @param frame The frame.
    @param inputBuffer The input buffer.
*/
- (void) doProcessFrame:(FMLiveSwitchVideoFrame*)frame inputBuffer:(FMLiveSwitchVideoBuffer*)inputBuffer;
/**

    Initializes a new instance of the FMLiveSwitchVpxEncoder class.

    @param outputFormat The output format.
*/
+ (FMLiveSwitchVpxEncoder*) encoderWithOutputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Gets a value indicating whether a keyframe should be forced.

*/
- (bool) forceKeyFrame;
/**

    Initializes a new instance of the FMLiveSwitchVpxEncoder class.

    @param outputFormat The output format.
*/
- (instancetype) initWithOutputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Determines whether the [buffer] contains a Key Frame.

    @param buffer The buffer.
*/
- (bool) isKeyFrameWithBuffer:(FMLiveSwitchDataBuffer*)buffer;
/**

    Gets the target output quality.

*/
- (double) quality;
/**

    Sets the encoder configuration.

    @return 0 on success, non-zero on failure.
*/
- (int) setCodecConfig:(FMLiveSwitchVpxEncoderConfig*)config;
/**

    Sets a value indicating whether a keyframe should be forced.

*/
- (void) setForceKeyFrame:(bool)value;
/**

    Sets the target output quality.

*/
- (void) setQuality:(double)value;

@end

/**

    Bit depths for VPX output.

*/
@interface FMLiveSwitchVpxBitDepth : NSObject

/**

    Gets a bit depth of 10 bits.

*/
+ (FMLiveSwitchVpxBitDepth*) bits10;
/**

    Gets a bit depth of 12 bits.

*/
+ (FMLiveSwitchVpxBitDepth*) bits12;
/**

    Gets a bit depth of 8 bits.

*/
+ (FMLiveSwitchVpxBitDepth*) bits8;
/**

    Gets the internal integer value representation of this end usage mode.

*/
- (int) value;

@end

/**

    End usage modes for VPX.

*/
@interface FMLiveSwitchVpxEndUsageMode : NSObject

/**

    Gets a KeyframeMode of type VPX_CBR.

*/
+ (FMLiveSwitchVpxEndUsageMode*) cbr;
/**

    Gets a KeyframeMode of type VPX_CQ.

*/
+ (FMLiveSwitchVpxEndUsageMode*) cq;
/**

    Gets a KeyframeMode of type VPX_Q.

*/
+ (FMLiveSwitchVpxEndUsageMode*) q;
/**

    Gets the internal integer value representation of this end usage mode.

*/
- (int) value;
/**

    Gets a KeyframeMode of type VPX_VBR.

*/
+ (FMLiveSwitchVpxEndUsageMode*) vbr;

@end

/**

    Keyframe modes for VPX.

*/
@interface FMLiveSwitchVpxKeyframeMode : NSObject

/**

    Gets a KeyframeMode of type Auto.

*/
+ (FMLiveSwitchVpxKeyframeMode*) auto;
/**

    Gets a KeyframeMode of type Disabled.

*/
+ (FMLiveSwitchVpxKeyframeMode*) disabled;
/**

    Gets a KeyframeMode of type Fixed. This is deprecated by VPX and is equivalent
    to KeyframeMode.Disabled.  To generate keyframes at fixed intervals, set the
    EncoderConfig.KeyframeMinDistance = EncoderConfig.KeyframeMaxDistance.

*/
+ (FMLiveSwitchVpxKeyframeMode*) fixed;
/**

    Gets the internal integer value representation of this keyframe mode.

*/
- (int) value;

@end

/**

    Config for the Vp8/Vp9 encoders. Properties map to VPX properties.
    http://www.webmproject.org/docs/webm-sdk/structvpx__codec__enc__cfg.html

*/
@interface FMLiveSwitchVpxEncoderConfig : NSObject

/**

    Gets a value that maps to "g_bit_depth".

*/
- (FMLiveSwitchVpxBitDepth*) bitDepth;
/**

    Gets a value that maps to "rc_buf_initial_sz".

*/
- (int) bufferInitialSize;
/**

    Gets a value that maps to "rc_buf_optimal_sz".

*/
- (int) bufferOptimalSize;
/**

    Gets a value that maps to "rc_buf_sz".

*/
- (int) bufferSize;
/**

    Gets a value used for "VP8E_SET_CPUUSED". Range is [-16, 16] for VP8 and [-8, 8] for VP9.

*/
- (int) cpu;
/**

    Gets a deep copy of this configuration.

*/
- (FMLiveSwitchVpxEncoderConfig*) deepCopy;
/**

    Gets a value that maps to "rc_dropframe_thresh".

*/
- (int) dropFrameThreshold;
/**

    Creates a new copy of the VPX encoder configurations with default values.

*/
+ (FMLiveSwitchVpxEncoderConfig*) encoderConfig;
/**

    Gets a value that maps to "rc_end_usage".

*/
- (FMLiveSwitchVpxEndUsageMode*) endUsageMode;
/**

    Gets a value that maps to g_error_resilient

*/
- (int) errorResilient;
/**

    Creates a new copy of the VPX encoder configurations with default values.

*/
- (instancetype) init;
/**

    Gets a value that maps to "g_input_bit_depth".

*/
- (int) inputBitDepth;
/**

    Gets a value that maps to "kf_max_dist".

*/
- (int) keyframeMaxDistance;
/**

    Gets a value that maps to "kf_min_dist".

*/
- (int) keyframeMinDistance;
/**

    Gets a value that makes to "kf_mode".

*/
- (FMLiveSwitchVpxKeyframeMode*) keyframeMode;
/**

    Gets a value that maps to "g_lag_in_frames".

*/
- (int) lagInFrames;
/**

    Gets a value that maps to "layer_trget_bitrater".

*/
- (NSMutableArray*) layerTargetBitrate;
/**

    Gets a value that maps to "rc_max_quantizer". If -1, then Quality field used.

*/
- (int) maxQuantizer;
/**

    Gets a value that maps to "rc_min_quantizer".

*/
- (int) minQuantizer;
/**

    Gets a value that maps to "rc_overshoot_pct".

*/
- (int) overshootPercentage;
/**

    Gets a value that maps to "g_profile".

*/
- (int) profile;
/**

    Gets a value that maps to "rc_resize_allowed".

*/
- (bool) resizeAllowed;
/**

    Gets a value that maps to "rc_resize_down_thresh".

*/
- (int) resizeDownThreshold;
/**

    Gets a value that maps to "rc_resize_up_thresh".

*/
- (int) resizeUpThreshold;
/**

    Gets a value that maps to "rc_scaled_height".

*/
- (int) scaledHeight;
/**

    Gets a value that maps to "rc_scaled_width".

*/
- (int) scaledWidth;
/**

    Sets a value that maps to "g_bit_depth".

*/
- (void) setBitDepth:(FMLiveSwitchVpxBitDepth*)value;
/**

    Sets a value that maps to "rc_buf_initial_sz".

*/
- (void) setBufferInitialSize:(int)value;
/**

    Sets a value that maps to "rc_buf_optimal_sz".

*/
- (void) setBufferOptimalSize:(int)value;
/**

    Sets a value that maps to "rc_buf_sz".

*/
- (void) setBufferSize:(int)value;
/**

    Sets a value used for "VP8E_SET_CPUUSED". Range is [-16, 16] for VP8 and [-8, 8] for VP9.

*/
- (void) setCpu:(int)value;
/**

    Sets a value that maps to "rc_dropframe_thresh".

*/
- (void) setDropFrameThreshold:(int)value;
/**

    Sets a value that maps to "rc_end_usage".

*/
- (void) setEndUsageMode:(FMLiveSwitchVpxEndUsageMode*)value;
/**

    Sets a value that maps to g_error_resilient

*/
- (void) setErrorResilient:(int)value;
/**

    Sets a value that maps to "g_input_bit_depth".

*/
- (void) setInputBitDepth:(int)value;
/**

    Sets a value that maps to "kf_max_dist".

*/
- (void) setKeyframeMaxDistance:(int)value;
/**

    Sets a value that maps to "kf_min_dist".

*/
- (void) setKeyframeMinDistance:(int)value;
/**

    Sets a value that makes to "kf_mode".

*/
- (void) setKeyframeMode:(FMLiveSwitchVpxKeyframeMode*)value;
/**

    Sets a value that maps to "g_lag_in_frames".

*/
- (void) setLagInFrames:(int)value;
/**

    Sets a value that maps to "layer_trget_bitrater".

*/
- (void) setLayerTargetBitrate:(NSMutableArray*)value;
/**

    Sets a value that maps to "rc_max_quantizer". If -1, then Quality field used.

*/
- (void) setMaxQuantizer:(int)value;
/**

    Sets a value that maps to "rc_min_quantizer".

*/
- (void) setMinQuantizer:(int)value;
/**

    Sets a value that maps to "rc_overshoot_pct".

*/
- (void) setOvershootPercentage:(int)value;
/**

    Sets a value that maps to "g_profile".

*/
- (void) setProfile:(int)value;
/**

    Sets a value that maps to "rc_resize_allowed".

*/
- (void) setResizeAllowed:(bool)value;
/**

    Sets a value that maps to "rc_resize_down_thresh".

*/
- (void) setResizeDownThreshold:(int)value;
/**

    Sets a value that maps to "rc_resize_up_thresh".

*/
- (void) setResizeUpThreshold:(int)value;
/**

    Sets a value that maps to "rc_scaled_height".

*/
- (void) setScaledHeight:(int)value;
/**

    Sets a value that maps to "rc_scaled_width".

*/
- (void) setScaledWidth:(int)value;
/**

    Sets a value that maps to "ss_enable_auto_alt_ref".

*/
- (void) setSpatialEnableAutoAltRef:(NSMutableArray*)value;
/**

    Sets a value that maps to "ss_number_layers".

*/
- (void) setSpatialLayers:(int)value;
/**

    Sets a value that maps to "ss_target_bitrate".

*/
- (void) setSpatialTargetBitrate:(NSMutableArray*)value;
/**

    Sets a value that maps to "temporal_layering_mode".

*/
- (void) setTemporalLayerMode:(FMLiveSwitchVpxTemporalLayerMode*)value;
/**

    Sets a value that maps to "ts_number_layers".

*/
- (void) setTemporalLayers:(int)value;
/**

    Sets a value that maps to "ts_layer_id".

*/
- (void) setTemporalPattern:(NSMutableArray*)value;
/**

    Sets a value that maps to "ts_periodicity".

*/
- (void) setTemporalPeriodicity:(int)value;
/**

    Sets a value that maps to "ts_rate_decimator".

*/
- (void) setTemporalRateDecimator:(NSMutableArray*)value;
/**

    Sets a value that maps to "ts_target_bitrate".

*/
- (void) setTemporalTargetBitrate:(NSMutableArray*)value;
/**

    Sets a value that maps to "g_threads".

*/
- (void) setThreads:(int)value;
/**

    Sets a value that maps to "g_timebase.den".

*/
- (void) setTimebaseDenominator:(int)value;
/**

    Sets a value that maps to "g_timebase.num".

*/
- (void) setTimebaseNumerator:(int)value;
/**

    Sets a value that maps to "rc_undershoot_pct".

*/
- (void) setUndershootPercentage:(int)value;
/**

    Sets a value that maps to "g_usage".

*/
- (void) setUsage:(int)value;
/**

    Gets a value that maps to "ss_enable_auto_alt_ref".

*/
- (NSMutableArray*) spatialEnableAutoAltRef;
/**

    Gets a value that maps to "ss_number_layers".

*/
- (int) spatialLayers;
/**

    Gets a value that maps to "ss_target_bitrate".

*/
- (NSMutableArray*) spatialTargetBitrate;
/**

    Gets a value that maps to "temporal_layering_mode".

*/
- (FMLiveSwitchVpxTemporalLayerMode*) temporalLayerMode;
/**

    Gets a value that maps to "ts_number_layers".

*/
- (int) temporalLayers;
/**

    Gets a value that maps to "ts_layer_id".

*/
- (NSMutableArray*) temporalPattern;
/**

    Gets a value that maps to "ts_periodicity".

*/
- (int) temporalPeriodicity;
/**

    Gets a value that maps to "ts_rate_decimator".

*/
- (NSMutableArray*) temporalRateDecimator;
/**

    Gets a value that maps to "ts_target_bitrate".

*/
- (NSMutableArray*) temporalTargetBitrate;
/**

    Gets a value that maps to "g_threads".

*/
- (int) threads;
/**

    Gets a value that maps to "g_timebase.den".

*/
- (int) timebaseDenominator;
/**

    Gets a value that maps to "g_timebase.num".

*/
- (int) timebaseNumerator;
/**

    Gets a value that maps to "rc_undershoot_pct".

*/
- (int) undershootPercentage;
/**

    Gets a value that maps to "g_usage".

*/
- (int) usage;

@end

/**

    Error resiliency flags for VPX.

*/
@interface FMLiveSwitchVpxErrorResilientType : NSObject

/**

    Gets the flag position for VPX_ERROR_RESILIENT_DEFAULT.

*/
+ (int) default;
/**

    Gets the flag position for VPX_ERROR_RESILIENT_PARTITIONS.

*/
+ (int) partitions;

@end

/**

    VPX-related utility functions.

*/
@interface FMLiveSwitchVpxUtility : NSObject

- (instancetype) init;
/**

    Initializes VPX native libraries.

*/
+ (bool) initialize;
+ (FMLiveSwitchVpxUtility*) utility;

@end

/**

    A libvpx-based VP8 decoder.

*/
@interface FMLiveSwitchVp8Decoder : FMLiveSwitchVpxDecoder

/**

    Gets the current codec.

*/
- (FMLiveSwitchVpxCodec) codec;
/**

    Initializes a new instance of the FMLiveSwitchVp8Decoder class.

*/
+ (FMLiveSwitchVp8Decoder*) decoder;
/**

    Initializes a new instance of the FMLiveSwitchVp8Decoder class.

    @param input The input.
*/
+ (FMLiveSwitchVp8Decoder*) decoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Initializes a new instance of the FMLiveSwitchVp8Decoder class.

*/
- (instancetype) init;
/**

    Initializes a new instance of the FMLiveSwitchVp8Decoder class.

    @param input The input.
*/
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Determines whether a data buffer represents a keyframe.

    @param dataBuffer The data buffer.
*/
- (bool) isKeyFrameWithDataBuffer:(FMLiveSwitchDataBuffer*)dataBuffer;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;

@end

/**

    A libvpx-based VP8 encoder.

*/
@interface FMLiveSwitchVp8Encoder : FMLiveSwitchVpxEncoder

/**

    Gets the current codec.

*/
- (FMLiveSwitchVpxCodec) codec;
/**

    Initializes a new instance of the FMLiveSwitchVp8Encoder class.

*/
+ (FMLiveSwitchVp8Encoder*) encoder;
/**

    Initializes a new instance of the FMLiveSwitchVp8Encoder class.

    @param input The input.
*/
+ (FMLiveSwitchVp8Encoder*) encoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Initializes a new instance of the FMLiveSwitchVp8Encoder class.

*/
- (instancetype) init;
/**

    Initializes a new instance of the FMLiveSwitchVp8Encoder class.

    @param input The input.
*/
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Determines whether the [buffer] contains a Key Frame.

    @param buffer The buffer.
*/
- (bool) isKeyFrameWithBuffer:(FMLiveSwitchDataBuffer*)buffer;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;

@end

/**

    A libvpx-based VP9 decoder.

*/
@interface FMLiveSwitchVp9Decoder : FMLiveSwitchVpxDecoder

/**

    Gets the current codec.

*/
- (FMLiveSwitchVpxCodec) codec;
/**

    Initializes a new instance of the FMLiveSwitchVp9Decoder class.

*/
+ (FMLiveSwitchVp9Decoder*) decoder;
/**

    Initializes a new instance of the FMLiveSwitchVp9Decoder class.

    @param input The input.
*/
+ (FMLiveSwitchVp9Decoder*) decoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Initializes a new instance of the FMLiveSwitchVp9Decoder class.

*/
- (instancetype) init;
/**

    Initializes a new instance of the FMLiveSwitchVp9Decoder class.

    @param input The input.
*/
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Determines whether a data buffer represents a keyframe.

    @param dataBuffer The data buffer.
*/
- (bool) isKeyFrameWithDataBuffer:(FMLiveSwitchDataBuffer*)dataBuffer;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;

@end

/**

    A libvpx-based VP9 encoder.

*/
@interface FMLiveSwitchVp9Encoder : FMLiveSwitchVpxEncoder

/**

    Gets the current codec.

*/
- (FMLiveSwitchVpxCodec) codec;
/**

    Initializes a new instance of the FMLiveSwitchVp9Encoder class.

*/
+ (FMLiveSwitchVp9Encoder*) encoder;
/**

    Initializes a new instance of the FMLiveSwitchVp9Encoder class.

    @param input The input.
*/
+ (FMLiveSwitchVp9Encoder*) encoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Initializes a new instance of the FMLiveSwitchVp9Encoder class.

*/
- (instancetype) init;
/**

    Initializes a new instance of the FMLiveSwitchVp9Encoder class.

    @param input The input.
*/
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Determines whether the [buffer] contains a Key Frame.

    @param buffer The buffer.
*/
- (bool) isKeyFrameWithBuffer:(FMLiveSwitchDataBuffer*)buffer;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;

@end

#pragma clang pop
