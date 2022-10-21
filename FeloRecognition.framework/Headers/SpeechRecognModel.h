//
//  SpeechRecognModel.m
//  Felo
//
//  Created by Felo on 2021/12/5.
//  Copyright © 2022 Sparticle inc. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void(^RfreshTokenBlock)(NSString *) ;
typedef void (^RreshAccessTokenBlock)(BOOL expired);
@protocol FeloSubtitleDelegate <NSObject>
//Here are some things you can do when the network goes down
- (void)disconnectServer;
//We will automatically reconnect the subtitle service when the network is restored
- (void)reconnectedServer;
@required
- (void)getSubtitle:(NSDictionary *)subTitle;
/// call when refresh token is expired
/// - Parameter refreshBlock: refreshBlock description
//- (void)refreshToken:(void(^)(NSString *))refreshBlock;

@end

@interface SpeechRecognModel : NSObject
+ (SpeechRecognModel *)sharedObject;

//It is recommended to open it so that the subtitle sdk can be automatically connected when the network is disconnected
@property (assign,nonatomic) BOOL autoConnect;

@property (copy,nonatomic)RreshAccessTokenBlock refreshBlock;
@property (weak,nonatomic) id<FeloSubtitleDelegate> delegate;
@property (strong,nonatomic) NSString *authToken;

/// start subtitle
/// - Parameters:
///   - params: params contian appid,accesstoken
///   - completeHandler: completeHandler description
- (void)startSubtitle:(NSMutableDictionary *)params completeHandler:(void (^)(BOOL))completeHandler;

/// leave room
/// - Parameters:
///   - completeHandler: completeHandler description
- (void)leaveConversation:(void (^)(BOOL flag))completeHandler;

/// set room language
/// - Parameters:
///   - bizId: bizid
///   - language: source language
///   - completeHandler: completeHandler description
- (void)setLanguage:(NSString *)bizId  language:(NSString *)language completeHandler:(void (^)(BOOL))completeHandler;


@end


