//
// Title: LiveSwitch YUV Extension for Cocoa
// Version: 0.0.0.0
// Copyright Frozen Mountain Software 2011+
//

#import <Foundation/Foundation.h>

#import "FMLiveSwitch.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wnullability-completeness"

@class FMLiveSwitchYuvNative;
@class FMLiveSwitchYuvFilterMode;
@class FMLiveSwitchYuvImageConverter;
@class FMLiveSwitchYuvImageScaler;
@class FMLiveSwitchYuvUtility;
/**

    A filter mode.

*/
@interface FMLiveSwitchYuvFilterMode : NSObject

/**

    Gets the value indicating bilinear.
    This is faster than box, but produces lower quality.

*/
+ (int) bilinear;
/**

    Gets the value indicating box.
    This is the slowest option, but produces the highest quality.

*/
+ (int) box;
+ (FMLiveSwitchYuvFilterMode*) filterMode;
- (instancetype) init;
/**

    Gets the value indicating linear (horizontal only).
    This is faster than bilinear, but produces lower quality.

*/
+ (int) linear;
/**

    Gets the value indicating no filter (point sample).
    This is the fastest option, but produces the lowest quality.

*/
+ (int) none;

@end

/**

    A libyuv-based image converter.

*/
@interface FMLiveSwitchYuvImageConverter : FMLiveSwitchImageScalePipe

/**

    Gets the alignment.

*/
- (int) alignment;
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

    Gets the filter mode.

*/
- (int) filterMode;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param input The input.
    @param outputFormat The output format.
*/
+ (FMLiveSwitchYuvImageConverter*) imageConverterWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param inputFormat The input format.
    @param outputFormat The output format.
*/
+ (FMLiveSwitchYuvImageConverter*) imageConverterWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param inputs The inputs.
    @param outputFormat The output format.
*/
+ (FMLiveSwitchYuvImageConverter*) imageConverterWithInputs:(NSMutableArray*)inputs outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param outputFormat The output format.
*/
+ (FMLiveSwitchYuvImageConverter*) imageConverterWithOutputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param input The input.
    @param outputFormat The output format.
*/
- (instancetype) initWithInput:(NSObject<FMLiveSwitchIVideoOutput>*)input outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param inputFormat The input format.
    @param outputFormat The output format.
*/
- (instancetype) initWithInputFormat:(FMLiveSwitchVideoFormat*)inputFormat outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param inputs The inputs.
    @param outputFormat The output format.
*/
- (instancetype) initWithInputs:(NSMutableArray*)inputs outputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageConverter class.

    @param outputFormat The output format.
*/
- (instancetype) initWithOutputFormat:(FMLiveSwitchVideoFormat*)outputFormat;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;
/**

    Sets the alignment.

*/
- (void) setAlignment:(int)value;
/**

    Sets the filter mode.

*/
- (void) setFilterMode:(int)value;

@end

/**

    A libyuv-based image scaler.

*/
@interface FMLiveSwitchYuvImageScaler : FMLiveSwitchImageScalePipe

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

    Gets the filter mode.

*/
- (int) filterMode;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageScaler class.

    @param scale The scale.
*/
+ (FMLiveSwitchYuvImageScaler*) imageScalerWithScale:(double)scale;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageScaler class.

    @param scale The scale.
    @param input The input.
*/
+ (FMLiveSwitchYuvImageScaler*) imageScalerWithScale:(double)scale input:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageScaler class.

    @param scale The scale.
    @param inputs The inputs.
*/
+ (FMLiveSwitchYuvImageScaler*) imageScalerWithScale:(double)scale inputs:(NSMutableArray*)inputs;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageScaler class.

    @param scale The scale.
*/
- (instancetype) initWithScale:(double)scale;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageScaler class.

    @param scale The scale.
    @param input The input.
*/
- (instancetype) initWithScale:(double)scale input:(NSObject<FMLiveSwitchIVideoOutput>*)input;
/**

    Initializes a new instance of the FMLiveSwitchYuvImageScaler class.

    @param scale The scale.
    @param inputs The inputs.
*/
- (instancetype) initWithScale:(double)scale inputs:(NSMutableArray*)inputs;
/**

    Gets a label that identifies this class.

*/
- (NSString*) label;
/**

    Sets the filter mode.

*/
- (void) setFilterMode:(int)value;

@end

/**

    YUV-related utility functions.

*/
@interface FMLiveSwitchYuvUtility : NSObject

- (instancetype) init;
/**

    Initializes YUV native libraries.

*/
+ (bool) initialize;
+ (FMLiveSwitchYuvUtility*) utility;

@end

#pragma clang pop
