//
// Title: LiveSwitch XirSys Extension for Cocoa
// Version: 0.0.0.0
// Copyright Frozen Mountain Software 2011+
//

#import <Foundation/Foundation.h>

#import "FMLiveSwitch.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wnullability-completeness"

@class FMLiveSwitchXirSysV2Client;
@class FMLiveSwitchXirSysV3Client;
/**

    A XirSys v2 client.

*/
@interface FMLiveSwitchXirSysV2Client : NSObject

/**

    Gets the "application" value.
    Defaults to "default".

*/
- (NSString*) application;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
*/
+ (FMLiveSwitchXirSysV2Client*) clientWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
    @param application The "application" value.
*/
+ (FMLiveSwitchXirSysV2Client*) clientWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain application:(NSString*)application;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
    @param application The "application" value.
    @param room The "room" value.
*/
+ (FMLiveSwitchXirSysV2Client*) clientWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain application:(NSString*)application room:(NSString*)room;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
    @param application The "application" value.
    @param room The "room" value.
    @param secure The "secure" value.
*/
+ (FMLiveSwitchXirSysV2Client*) clientWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain application:(NSString*)application room:(NSString*)room secure:(bool)secure;
/**

    Gets the default HTTP endpoint.
    Defaults to "https://service.xirsys.com/ice".

*/
+ (NSString*) defaultEndpoint;
/**

    Gets the "domain" value.

*/
- (NSString*) domain;
/**

    Gets the HTTP endpoint.

*/
- (NSString*) endpoint;
/**

    Gets an array of XirSys ICE servers.

*/
- (FMLiveSwitchFuture<NSMutableArray*>*) getIceServers;
/**

    Gets the "ident" value.

*/
- (NSString*) ident;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
*/
- (instancetype) initWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
    @param application The "application" value.
*/
- (instancetype) initWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain application:(NSString*)application;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
    @param application The "application" value.
    @param room The "room" value.
*/
- (instancetype) initWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain application:(NSString*)application room:(NSString*)room;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV2Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param domain The "domain" value.
    @param application The "application" value.
    @param room The "room" value.
    @param secure The "secure" value.
*/
- (instancetype) initWithIdent:(NSString*)ident secret:(NSString*)secret domain:(NSString*)domain application:(NSString*)application room:(NSString*)room secure:(bool)secure;
/**

    Gets the "room" value.
    Defaults to "default".

*/
- (NSString*) room;
/**

    Gets the "secret" value.

*/
- (NSString*) secret;
/**

    Gets the "secure" value.
    Defaults to `true`.

*/
- (bool) secure;
/**

    Sets the "application" value.
    Defaults to "default".

*/
- (void) setApplication:(NSString*)value;
/**

    Sets the default HTTP endpoint.
    Defaults to "https://service.xirsys.com/ice".

*/
+ (void) setDefaultEndpoint:(NSString*)value;
/**

    Sets the "domain" value.

*/
- (void) setDomain:(NSString*)value;
/**

    Sets the HTTP endpoint.

*/
- (void) setEndpoint:(NSString*)value;
/**

    Sets the "ident" value.

*/
- (void) setIdent:(NSString*)value;
/**

    Sets the "room" value.
    Defaults to "default".

*/
- (void) setRoom:(NSString*)value;
/**

    Sets the "secret" value.

*/
- (void) setSecret:(NSString*)value;
/**

    Sets the "secure" value.
    Defaults to `true`.

*/
- (void) setSecure:(bool)value;

@end

/**

    A XirSys v3 client.

*/
@interface FMLiveSwitchXirSysV3Client : NSObject

/**

    Gets the "channel" value.

*/
- (NSString*) channel;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV3Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param channel The "channel" value.
*/
+ (FMLiveSwitchXirSysV3Client*) clientWithIdent:(NSString*)ident secret:(NSString*)secret channel:(NSString*)channel;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV3Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param channel The "channel" value.
    @param secure The "secure" value.
*/
+ (FMLiveSwitchXirSysV3Client*) clientWithIdent:(NSString*)ident secret:(NSString*)secret channel:(NSString*)channel secure:(bool)secure;
/**

    Gets the default HTTP endpoint.
    Defaults to "https://global.xirsys.net/_turn".

*/
+ (NSString*) defaultEndpoint;
/**

    Gets the HTTP endpoint.

*/
- (NSString*) endpoint;
/**

    Gets an array of XirSys ICE servers.

*/
- (FMLiveSwitchFuture<NSMutableArray*>*) getIceServers;
/**

    Gets the "ident" value.

*/
- (NSString*) ident;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV3Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param channel The "channel" value.
*/
- (instancetype) initWithIdent:(NSString*)ident secret:(NSString*)secret channel:(NSString*)channel;
/**

    Initializes a new instance of the FMLiveSwitchXirSysV3Client class.

    @param ident The "ident" value.
    @param secret The "secret" value.
    @param channel The "channel" value.
    @param secure The "secure" value.
*/
- (instancetype) initWithIdent:(NSString*)ident secret:(NSString*)secret channel:(NSString*)channel secure:(bool)secure;
/**

    Gets the "secret" value.

*/
- (NSString*) secret;
/**

    Gets the "secure" value.
    Defaults to `true`.

*/
- (bool) secure;
/**

    Sets the "channel" value.

*/
- (void) setChannel:(NSString*)value;
/**

    Sets the default HTTP endpoint.
    Defaults to "https://global.xirsys.net/_turn".

*/
+ (void) setDefaultEndpoint:(NSString*)value;
/**

    Sets the HTTP endpoint.

*/
- (void) setEndpoint:(NSString*)value;
/**

    Sets the "ident" value.

*/
- (void) setIdent:(NSString*)value;
/**

    Sets the "secret" value.

*/
- (void) setSecret:(NSString*)value;
/**

    Sets the "secure" value.
    Defaults to `true`.

*/
- (void) setSecure:(bool)value;

@end

#pragma clang pop
