/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBControlCore.h>
#import <FBSimulatorControl/FBSimulatorScale.h>

@class FBDiagnostic;
@class FBSimulator;
@class FBVideoEncoderConfiguration;

NS_ASSUME_NONNULL_BEGIN

/**
 A Configuration Value for a Framebuffer.
 */
@interface FBFramebufferConfiguration : NSObject <NSCoding, NSCopying, FBJSONSerializable, FBDebugDescribeable>

/**
 The Scale of the Framebuffer.
 */
@property (nonatomic, nullable, copy, readonly) FBSimulatorScale scale;

/**
 The Video Encoder Configuration.
 */
@property (nonatomic, strong, readonly) FBVideoEncoderConfiguration *encoder;

/**
 The Default Image Path to write to.
 */
@property (nonatomic, strong, readonly) NSString *imagePath;

/**
 Creates and Returns a new FBFramebufferConfiguration Value with the provided parameters.

 @param scale the Scale of the Framebuffer.
 @return a FBFramebufferConfiguration instance.
 */
+ (instancetype)configurationWithScale:(nullable FBSimulatorScale)scale encoder:(FBVideoEncoderConfiguration *)encoder imagePath:(NSString *)imagePath;

/**
 The Default Configuration.
 */
+ (instancetype)defaultConfiguration;

#pragma mark Scale

/**
 Returns a new Configuration with the Scale Applied.
 */
- (instancetype)withScale:(nullable FBSimulatorScale)scale;
+ (instancetype)withScale:(nullable FBSimulatorScale)scale;

/**
 The Scale, as a Decimal.
 */
- (nullable NSDecimalNumber *)scaleValue;

/**
 Scales the provided size with the receiver's scale.

 @param size the size to scale.
 @return a scaled size.
 */
- (CGSize)scaleSize:(CGSize)size;

#pragma mark Encoder

/**
 Returns a Configuration with the Encoder Applied.
 */
+ (instancetype)withEncoder:(FBVideoEncoderConfiguration *)encoder;
- (instancetype)withEncoder:(FBVideoEncoderConfiguration *)encoder;

#pragma mark Image Path

/**
 Returns a new Configuration with the Diagnostic Applied.
 */
+ (instancetype)withImagePath:(NSString *)imagePath;
- (instancetype)withImagePath:(NSString *)imagePath;
+ (instancetype)withImageDiagnostic:(FBDiagnostic *)diagnostic;
- (instancetype)withImageDiagnostic:(FBDiagnostic *)diagnostic;

#pragma mark Simulators

/**
 Returns a new Configuration with the diagnostic paths from the Simulator.
 */
- (instancetype)inSimulator:(FBSimulator *)simulator;

@end

NS_ASSUME_NONNULL_END
