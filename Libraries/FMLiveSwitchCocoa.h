//
// Title: LiveSwitch Cocoa Extension for Cocoa
// Version: 0.0.0.0
// Copyright Frozen Mountain Software 2011+
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#if !TARGET_OS_TV
#import <VideoToolbox/VideoToolbox.h>
#endif
#if TARGET_OS_IPHONE
#import <GLKit/GLKit.h>
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
#endif

#import "FMLiveSwitch.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wnullability-completeness"

@class FMLiveSwitchCocoaAudioUnitSink;
@class FMLiveSwitchCocoaAudioUnitSource;
@class FMLiveSwitchCocoaAVCapturePreview;
@class FMLiveSwitchCocoaAVCaptureSource;
@class FMLiveSwitchCocoaImageUtility;
@class FMLiveSwitchCocoaImageViewSink;
@class FMLiveSwitchCocoaLayoutContainer;
@class FMLiveSwitchCocoaLayoutManager;
@class FMLiveSwitchCocoaOpenGLSink;
@class FMLiveSwitchCocoaOpenGLView;
@class FMLiveSwitchCocoaScreenSource;
@class FMLiveSwitchCocoaUtility;
@class FMLiveSwitchCocoaVideoToolboxBaseDecoder;
@class FMLiveSwitchCocoaVideoToolboxBaseEncoder;
@class FMLiveSwitchCocoaVideoToolboxH264Decoder;
@class FMLiveSwitchCocoaVideoToolboxH264Encoder;
@class FMLiveSwitchCocoaVideoToolboxH265Decoder;
@class FMLiveSwitchCocoaVideoToolboxH265Encoder;

#if TARGET_OS_IPHONE


@interface FMLiveSwitchVideoConfig (FMLiveSwitchCocoaExtensions)

- (instancetype)initWithPreset:(NSString *)preset frameRate:(int)frameRate;
- (instancetype)initWithPreset:(NSString *)preset frameRate:(int)frameRate clockRate:(int)clockRate;
- (NSString *)preset;
@end

#endif



#if TARGET_OS_IPHONE
#else
#endif

#if TARGET_OS_IPHONE
#define FM_VIEW UIView
#define FM_IMAGE UIImage
#define FM_IMAGE_VIEW UIImageView
#define FM_RECT CGRect
#else
#define FM_VIEW NSView
#define FM_IMAGE NSImage
#define FM_IMAGE_VIEW NSImageView
#define FM_RECT NSRect
#endif


@interface FMLiveSwitchCocoaImageUtility : NSObject

+ (FMLiveSwitchVideoBuffer *)imageToBuffer:(FM_IMAGE *)image;
+ (FM_IMAGE *)bufferToImage:(FMLiveSwitchVideoBuffer *)buffer;
+ (FMLiveSwitchVideoBuffer *)cgImageToBuffer:(CGImageRef)cgImage;
+ (CGImageRef)newCGImageFromBuffer:(FMLiveSwitchVideoBuffer *)buffer;

@end



@interface FMLiveSwitchCocoaAudioUnitSource : FMLiveSwitchAudioSource

- (bool)useVoiceProcessingIO;
- (void)setUseVoiceProcessingIO:(bool)useVoiceProcessingIO;
- (bool)bypassVoiceProcessing;
- (void)setBypassVoiceProcessing:(bool)bypassVoiceProcessing;
- (bool)voiceProcessingEnableAGC;
- (void)setVoiceProcessingEnableAGC:(bool)voiceProcessingEnableAGC;
#if TARGET_OS_IPHONE
- (bool)observeInterruptions;
- (void)setObserveInterruptions:(bool)observeInterruptions;
#endif

/* static init */ + (instancetype)audioUnitSourceWithConfig:(FMLiveSwitchAudioConfig *)config;
- (instancetype)initWithConfig:(FMLiveSwitchAudioConfig *)config;

@end




@interface FMLiveSwitchCocoaAudioUnitSink : FMLiveSwitchAudioSink

- (bool)useVoiceProcessingIO;
- (void)setUseVoiceProcessingIO:(bool)useVoiceProcessingIO;

/* static init */ + (instancetype)audioUnitSinkWithConfig:(FMLiveSwitchAudioConfig *)config;
- (instancetype)initWithConfig:(FMLiveSwitchAudioConfig *)config;
/* static init */ + (instancetype)audioUnitSinkWithInput:(NSObject<FMLiveSwitchIAudioOutput> *)input;
- (instancetype)initWithInput:(NSObject<FMLiveSwitchIAudioOutput> *)input;
/* static init */ + (instancetype)audioUnitSinkWithInputs:(NSMutableArray *)inputs;
- (instancetype)initWithInputs:(NSMutableArray *)inputs;

@end


#if !TARGET_OS_TV

#if TARGET_OS_IPHONE



@interface FMLiveSwitchCocoaAVCapturePreview : UIView

@property FMLiveSwitchLayoutScale scale;
@property bool mirror;
@property bool muted;

/* static init */ + (instancetype)avCapturePreview;
- (instancetype)init;
/* static init */ + (instancetype)avCapturePreviewWithFrame:(CGRect)frame;
- (instancetype)initWithFrame:(CGRect)frame;

@end

#endif

#endif


#if !TARGET_OS_TV

#if TARGET_OS_IPHONE
#endif


@interface FMLiveSwitchCocoaAVCaptureSource : FMLiveSwitchCameraSourceBase<AVCaptureVideoDataOutputSampleBufferDelegate>

- (AVCaptureSession *)session;
- (AVCaptureDevice *)device;

#if TARGET_OS_IPHONE
- (FMLiveSwitchSourceInput *)frontInput;
- (FMLiveSwitchSourceInput *)backInput;
#endif

#if TARGET_OS_IPHONE
/* static init */ + (instancetype)avCaptureSourceWithPreview:(FMLiveSwitchCocoaAVCapturePreview *)preview config:(FMLiveSwitchVideoConfig *)targetConfig;
- (instancetype)initWithPreview:(FMLiveSwitchCocoaAVCapturePreview *)preview config:(FMLiveSwitchVideoConfig *)targetConfig;
#else
/* static init */ + (instancetype)avCaptureSourceWithConfig:(FMLiveSwitchVideoConfig *)targetConfig;
- (instancetype)initWithConfig:(FMLiveSwitchVideoConfig *)targetConfig;
#endif

@end

#endif




@interface FMLiveSwitchCocoaImageViewSink : FMLiveSwitchViewSink<FM_IMAGE_VIEW*>

/* static init */ + (instancetype)imageViewSink;
- (instancetype)init;
/* static init */ + (instancetype)imageViewSinkWithInput:(NSObject<FMLiveSwitchIVideoOutput> *)input;
- (instancetype)initWithInput:(NSObject<FMLiveSwitchIVideoOutput> *)input;
/* static init */ + (instancetype)imageViewSinkWithInputs:(NSMutableArray *)inputs;
- (instancetype)initWithInputs:(NSMutableArray *)inputs;
/* static init */ + (instancetype)imageViewSinkWithView:(FM_IMAGE_VIEW *)view;
- (instancetype)initWithView:(FM_IMAGE_VIEW *)view;
/* static init */ + (instancetype)imageViewSinkWithView:(FM_IMAGE_VIEW *)view input:(NSObject<FMLiveSwitchIVideoOutput> *)input;
- (instancetype)initWithView:(FM_IMAGE_VIEW *)view input:(NSObject<FMLiveSwitchIVideoOutput> *)input;
/* static init */ + (instancetype)imageViewSinkWithView:(FM_IMAGE_VIEW *)view inputs:(NSMutableArray *)inputs;
- (instancetype)initWithView:(FM_IMAGE_VIEW *)view inputs:(NSMutableArray *)inputs;

- (void)renderBufferWithInputBuffer:(FMLiveSwitchVideoBuffer *)buffer;
- (void)renderImage:(FM_IMAGE *)image;

@end




@protocol FMLiveSwitchCocoaLayoutContainerDelegate;

@interface FMLiveSwitchCocoaLayoutContainer : FM_VIEW

@property (nonatomic, assign) id<FMLiveSwitchCocoaLayoutContainerDelegate> delegate;

@end

@protocol FMLiveSwitchCocoaLayoutContainerDelegate

- (void)layoutContainer:(FMLiveSwitchCocoaLayoutContainer *)layoutContainer didSetFrame:(FM_RECT)frame;

@end



@interface FMLiveSwitchCocoaLayoutManager : FMLiveSwitchLayoutManager<FM_VIEW*><FMLiveSwitchCocoaLayoutContainerDelegate>

- (FM_VIEW *)container;

/* static init */ + (instancetype)layoutManagerWithContainer:(FM_VIEW *)container;
- (instancetype)initWithContainer:(FM_VIEW *)container;
/* static init */ + (instancetype)layoutManagerWithContainer:(FM_VIEW *)container preset:(FMLiveSwitchLayoutPreset *)preset;
- (instancetype)initWithContainer:(FM_VIEW *)container preset:(FMLiveSwitchLayoutPreset *)preset;

@end


#if TARGET_OS_IPHONE



@interface FMLiveSwitchCocoaOpenGLView : UIView<GLKViewDelegate>

- (FMLiveSwitchLayoutScale)scale;

/* static init */ + (instancetype)openGLView;
- (instancetype)init;
/* static init */ + (instancetype)openGLViewWithFrame:(CGRect)frame;
- (instancetype)initWithFrame:(CGRect)frame;
/* static init */ + (instancetype)openGLViewWithFrame:(CGRect)frame scale:(FMLiveSwitchLayoutScale)scale;
- (instancetype)initWithFrame:(CGRect)frame scale:(FMLiveSwitchLayoutScale)scale;
/* static init */ + (instancetype)openGLViewWithScale:(FMLiveSwitchLayoutScale)scale;
- (instancetype)initWithScale:(FMLiveSwitchLayoutScale)scale;

@end

#endif




#if TARGET_OS_IPHONE



@interface FMLiveSwitchCocoaOpenGLSink : FMLiveSwitchViewSink<FMLiveSwitchCocoaOpenGLView*>

/* static init */ + (instancetype)openGLSink;
- (instancetype)init;
/* static init */ + (instancetype)openGLSinkWithInput:(NSObject<FMLiveSwitchIVideoOutput> *)input;
- (instancetype)initWithInput:(NSObject<FMLiveSwitchIVideoOutput> *)input;
/* static init */ + (instancetype)openGLSinkWithInputs:(NSMutableArray *)inputs;
- (instancetype)initWithInputs:(NSMutableArray *)inputs;
/* static init */ + (instancetype)openGLSinkWithViewScale:(FMLiveSwitchLayoutScale)viewScale;
- (instancetype)initWithViewScale:(FMLiveSwitchLayoutScale)viewScale;
/* static init */ + (instancetype)openGLSinkWithViewScale:(FMLiveSwitchLayoutScale)viewScale input:(NSObject<FMLiveSwitchIVideoOutput> *)input;
- (instancetype)initWithViewScale:(FMLiveSwitchLayoutScale)viewScale input:(NSObject<FMLiveSwitchIVideoOutput> *)input;
/* static init */ + (instancetype)openGLSinkWithViewScale:(FMLiveSwitchLayoutScale)viewScale inputs:(NSMutableArray *)inputs;
- (instancetype)initWithViewScale:(FMLiveSwitchLayoutScale)viewScale inputs:(NSMutableArray *)inputs;
/* static init */ + (instancetype)openGLSinkWithView:(FMLiveSwitchCocoaOpenGLView *)view;
- (instancetype)initWithView:(FMLiveSwitchCocoaOpenGLView *)view;
/* static init */ + (instancetype)openGLSinkWithView:(FMLiveSwitchCocoaOpenGLView *)view input:(NSObject<FMLiveSwitchIVideoOutput> *)input;
- (instancetype)initWithView:(FMLiveSwitchCocoaOpenGLView *)view input:(NSObject<FMLiveSwitchIVideoOutput> *)input;
/* static init */ + (instancetype)openGLSinkWithView:(FMLiveSwitchCocoaOpenGLView *)view inputs:(NSMutableArray *)inputs;
- (instancetype)initWithView:(FMLiveSwitchCocoaOpenGLView *)view inputs:(NSMutableArray *)inputs;

- (void)renderBufferWithInputBuffer:(FMLiveSwitchVideoBuffer *)buffer;

@end

#endif



#if TARGET_OS_IPHONE
#endif


@interface FMLiveSwitchCocoaScreenSource : FMLiveSwitchScreenSourceBase

/* static init */ + (instancetype)screenSourceWithFrameRate:(double)frameRate;
- (instancetype)initWithFrameRate:(double)frameRate;
#if TARGET_OS_IPHONE
/* static init */ + (instancetype)screenSourceWithFrameRate:(double)frameRate view:(UIView *)view;
- (instancetype)initWithFrameRate:(double)frameRate view:(UIView *)view;
#endif

@end

#if !TARGET_OS_TV
#if TARGET_OS_IPHONE
#endif


@interface FMLiveSwitchCocoaVideoToolboxBaseEncoder : FMLiveSwitchVideoEncoder

/* static init */ + (instancetype) videoToolboxBaseEncoderWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
- (instancetype) initWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;

/*!
 * <div>
 * Gets the max payload size.
 * </div><value>
 * The max payload size.
 * </value>
 */
- (int) maxPayloadSize;
/*!
 * <div>
 * Sets the max payload size.
 * </div><value>
 * The max payload size.
 * </value>
 */
- (void) setMaxPayloadSize:(int)value;
/*!
 * <div>
 * Gets a value indicating whether a keyframe should be forced.
 * </div>
 */
- (bool) forceKeyFrame;
/*!
 * <div>
 * Sets a value indicating whether a keyframe should be forced.
 * </div>
 */
- (void) setForceKeyFrame:(bool)value;
/*!
 * <div>
 * Processes a frame.
 * </div>
 * @param frame The frame.
 * @param inputBuffer The input buffer.
 * @param outputFormat The output format.
 */
- (void) doProcessFrame:(FMLiveSwitchVideoFrame*)frame inputBuffer:(FMLiveSwitchVideoBuffer*)inputBuffer;

- (void)receiveCompressFailure:(OSStatus)status;

- (bool) createPixelBufferWithBuffer:(FMLiveSwitchVideoBuffer *)buffer
                     pixelBufferPool:(CVPixelBufferPoolRef *)pixelBufferPool
                     pixelBufferSpec:(NSDictionary *)pixelBufferSpec
							  output:(CVPixelBufferRef *)pixelBuffer;

- (void)encodeWithBuffer:(FMLiveSwitchVideoBuffer*)buffer frame:(FMLiveSwitchVideoFrame*)frame outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;

/*!
 * <div>
 * Destroys this instance.
 * </div>
 */
- (void) doDestroy;

@end

#endif


#if !TARGET_OS_TV
#if TARGET_OS_IPHONE
#endif


@class FMLiveSwitchVideoEncoder;
@class FMLiveSwitchVideoFrame;
@class FMLiveSwitchVideoBuffer;
@class FMLiveSwitchVideoFormat;
@protocol FMLiveSwitchIVideoOutput;
@class NSStringFMLiveSwitchExtensions;

@interface FMLiveSwitchCocoaVideoToolboxH264Encoder : FMLiveSwitchCocoaVideoToolboxBaseEncoder

/*!
 * <div>
 * Processes an SDP media description.
 * </div>
 * @param mediaDescription The media description.
 * @param isOffer if set to true [is offer].
 * @param isLocalDescription if set to true [is local description].
 */
- (FMLiveSwitchError*) doProcessSdpMediaDescription:(FMLiveSwitchSdpMediaDescription*)mediaDescription isOffer:(bool)isOffer isLocalDescription:(bool)isLocalDescription;
/*!
 * <div>
 * Initializes a new instance of the FMLiveSwitchOpenH264Encoder class.
 * </div>
 * @param input The input.
 */
/* static init */ + (instancetype) videoToolboxH264EncoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/*!
 * <div>
 * Gets a label that identifies this class.
 * </div>
 */
- (NSString*) label;
/*!
 * <div>
 * Gets the profile level identifier.
 * </div><value>
 * The profile level identifier.
 * </value>
 */
- (FMLiveSwitchH264ProfileLevelId*) profileLevelId;
/*!
 * <div>
 * Gets the supported profile idcs. Currently, only baseline is supported.
 * </div><value>
 * The supported profile idcs.
 * </value>
 */
- (NSMutableArray*) supportedProfileIdcs;

- (void)receiveCompressSampleBuffer:(CMSampleBufferRef)sampleBuffer outputFormat:(FMLiveSwitchVideoFormat*)outputFormat frame:(FMLiveSwitchVideoFrame*)frame width:(int)width height:(int)height;

/* static init */ + (instancetype) videoToolboxH264Encoder;
- (instancetype) init;
@end

#endif


#if !TARGET_OS_TV
#if TARGET_OS_IPHONE
#endif


@interface FMLiveSwitchCocoaVideoToolboxH265Encoder : FMLiveSwitchCocoaVideoToolboxBaseEncoder

/*!
 * <div>
 * Initializes a new instance of the FMLiveSwitchOpenH264Encoder class.
 * Available in iOS 11+, MacOS 10.13+
 * </div>
 * @param input The input.
 */
/* static init */ + (instancetype) videoToolboxH265EncoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;

/*!
 * <div>
 * Gets a label that identifies this class.
 * </div>
 */
- (NSString*) label;

- (void)receiveCompressSampleBuffer:(CMSampleBufferRef)sampleBuffer outputFormat:(FMLiveSwitchVideoFormat*)outputFormat frame:(FMLiveSwitchVideoFrame*)frame width:(int)width height:(int)height;

/*!
* <div>
* Initializes a new instance of the FMLiveSwitchOpenH264Encoder class.
* Available in iOS 11+, MacOS 10.13+
* </div>
*/
/* static init */ + (instancetype) videoToolboxH265Encoder;
- (instancetype) init;

@end

#endif


#if !TARGET_OS_TV
#if TARGET_OS_IPHONE
#endif

/// <summary>
/// A VideoToolbox-based decoder.
/// </summary>

@interface FMLiveSwitchCocoaVideoToolboxBaseDecoder : FMLiveSwitchVideoDecoder

@property bool needsKeyFrame;

/* static init */ + (instancetype) videoToolboxBaseDecoderWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
- (instancetype) initWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;

- (void) receiveDecompressFailure:(OSStatus)status infoFlags:(VTDecodeInfoFlags)infoFlags;

- (void) receiveDecompressImageBuffer:(CVImageBufferRef)imageBuffer outputFormat:(FMLiveSwitchVideoFormat*)outputFormat frame:(FMLiveSwitchVideoFrame*)frame;

- (bool) createDecompressionSessionWithFormatDescription:(CMFormatDescriptionRef)formatDescription output:(VTDecompressionSessionRef *)decompressionSession;

@end
#endif


#if !TARGET_OS_TV
#if TARGET_OS_IPHONE
#endif


@protocol FMLiveSwitchIVideoOutput;
@class FMLiveSwitchVideoFrame;
@class FMLiveSwitchVideoBuffer;
@class FMLiveSwitchVideoFormat;
@class FMLiveSwitchError;
@class FMLiveSwitchSdpMediaDescription;
@class NSStringFMLiveSwitchExtensions;

/// <summary>
/// An VideoToolbox-based H.264 decoder.
/// </summary>
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"

@interface FMLiveSwitchCocoaVideoToolboxH264Decoder : FMLiveSwitchCocoaVideoToolboxBaseDecoder

@property bool debugMode;

- (void)destroy;

/// <summary>
/// Initializes a new instance of the <see cref="FMLiveSwitchOpenH264Decoder" /> class.
/// </summary>
/* static init */ + (instancetype) videoToolboxH264Decoder;
- (instancetype) init;
/// <summary>
/// Initializes a new instance of the <see cref="FMLiveSwitchOpenH264Decoder" /> class.
/// </summary>
/// <param name="input">The input.</param>
/* static init */ + (instancetype) videoToolboxH264DecoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/// <summary>
/// Gets a label that identifies this class.
/// </summary>
- (NSString*) label;
@end
#endif


#if !TARGET_OS_TV
#if TARGET_OS_IPHONE
#endif

/// <summary>
/// A VideoToolbox-based H.265 decoder.
/// </summary>

@interface FMLiveSwitchCocoaVideoToolboxH265Decoder : FMLiveSwitchCocoaVideoToolboxBaseDecoder

- (void)destroy;

/// <summary>
/// Initializes a new instance of the <see cref="FMLiveSwitchOpenH265Decoder" /> class.
/// </summary>
/* static init */ + (instancetype) videoToolboxH265Decoder;
- (instancetype) init;

/// <summary>
/// Initializes a new instance of the <see cref="FMLiveSwitchOpenH265Decoder" /> class.
/// </summary>
/// <param name="input">The input.</param>
/* static init */ + (instancetype) videoToolboxH265DecoderWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input;

/// <summary>
/// Gets a label that identifies this class.
/// </summary>
- (NSString*) label;


@end
#endif


#pragma clang pop
