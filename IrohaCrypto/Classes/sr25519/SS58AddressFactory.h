//
//  SS58AddressFactory.h
//  IrohaCrypto
//
//  Created by Ruslan Rezin on 01.07.2020.
//

#import <Foundation/Foundation.h>
#import "IRCryptoKey.h"

typedef NS_ENUM(NSUInteger, SNAddressFactoryError) {
    SNAddressFactoryUnsupported,
    SNAddressFactoryIncorrectChecksum,
    SNAddressFactoryUnexpectedType
};

@protocol SS58AddressFactoryProtocol

- (nullable NSString*)addressFromPublicKey:(id<IRPublicKeyProtocol> _Nonnull)publicKey
                                      type:(UInt8)type
                                     error:(NSError*_Nullable*_Nullable)error;

- (nullable NSData*)accountIdFromAddress:(nonnull NSString*)address
                                    type:(UInt8)type
                                   error:(NSError*_Nullable*_Nullable)error;

- (nullable NSNumber*)typeFromAddress:(nonnull NSString*)address
                                error:(NSError*_Nullable*_Nullable)error;

@end

@interface SS58AddressFactory : NSObject<SS58AddressFactoryProtocol>

@end
