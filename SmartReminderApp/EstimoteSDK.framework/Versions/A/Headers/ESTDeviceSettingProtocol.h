//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingProtocol.h"


@protocol ESTDeviceSettingProtocol <ESTSettingProtocol>

@required

/**
 *  ID of register should be requested to read or write value for setting.
 *
 *  @return NSInteger value representing register ID
 */
- (uint16_t)registerID;

/**
 *  Method returns value converted to NSDate object that can be used
 *  to save value to the device.
 *
 *  @return NSDate representing setting value
 */
- (NSData *)getValueData;

/**
 *  Method updates setting value based on NSData object delivered from the device.
 *  Parsing is done during the operation.
 *
 *  @param data NSData delivered from the device.
 */
- (void)updateValueWithData:(NSData *)data;

/**
 *  Allows to validate if particular settings is available for firmware
 *  in version running on the device.
 *
 *  @param firmware Version of firmware running on the device
 *
 *  @return BOOL value indicating availability
 */
- (BOOL)isAvailableForFirmwareVersion:(NSString *)firmwareVersion;

@optional

/**
* Implement this method to check if value passed
* to your setting is correct.
* Return nil if it is, otherwise return error with description.
* You should use ESTErrorCodeInvalidValue as a error code.
*/
- (NSError *)validateValue;

@end
