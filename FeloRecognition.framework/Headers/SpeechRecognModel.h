//
//  SpeechRecognModel.m
//  Felo
//
//  Created by Felo on 2021/12/5.
//  Copyright © 2022 Sparticle inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol FeloSubtitleDelegate <NSObject>
//Here are some things you can do when the network goes down
- (void)disconnectServer;
//We will automatically reconnect the subtitle service when the network is restored
- (void)reconnectedServer;

@required
- (void)getSubtitle:(NSDictionary *)subTitle;

@end

@interface SpeechRecognModel : NSObject
+ (SpeechRecognModel *)sharedObject;

@property (assign,nonatomic) BOOL autoConnect;//It is recommended to open it so that the subtitle sdk can be automatically connected when the network is disconnected
@property (weak,nonatomic) id<FeloSubtitleDelegate> delegate;

/// start subtitle
/// - Parameters:
///   - params: params contian appid,accesstoken
///   - completeHandler: completeHandler description
- (void)startSubtitle:(NSMutableDictionary *)params completeHandler:(void (^)(BOOL))completeHandler;
/// GET MQTT INFO
/// @param clientType WEB、DESKTOP、IOS、ANDROID
/// @param completeHandler completeHandler description
//- (void)getMqttInfo:(NSString *)clientType completeHandler:(void (^)(NSDictionary *))completeHandler;

/// get auth token for userid
/// @param userID userID description
//- (void)getAuthToken:(NSString *)userID completeHandler:(void(^)(NSDictionary *))completeHandler;

//- (void)refreshToken:(NSString *)grant_type  completeHandler:(void (^)(NSDictionary *))completeHandler;

/// Description
/// @param bizId bizId description
/// @param language language description
/// @param completeHandler completeHandler description
//- (void)createConversation:(NSString *)bizId language:(NSString *)language completeHandler:(void (^)(BOOL ))completeHandler;

/// get conversation
/// @param bizId <#bizId description#>
/// @param completeHandler <#completeHandler description#>
//- (void)getConversation:(NSString *)bizId  completeHandler:(void (^)(NSDictionary *))completeHandler;

//- (void)joinConversation:(NSString *)bizId  completeHandler:(void (^)(NSDictionary *))completeHandler;

/// leave room
/// - Parameters:
///   - bizId: bizid
///   - completeHandler: completeHandler description
- (void)leaveConversation:(NSString *)bizId  completeHandler:(void (^)(BOOL flag))completeHandler;

/// set room language
/// - Parameters:
///   - bizId: bizid
///   - language: source language
///   - completeHandler: completeHandler description
- (void)setLanguage:(NSString *)bizId  language:(NSString *)language completeHandler:(void (^)(BOOL))completeHandler;


@end


