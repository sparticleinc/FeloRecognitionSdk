//
//  SpeechRecognModel.m
//  Felo
//
//  Created by Felo on 2021/12/5.
//  Copyright © 2022 Sparticle inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol FeloSubtitleDelegate <NSObject>
- (void)getSubtitle:(NSDictionary *)subTitle;
//Here are some things you can do when the network goes down
- (void)disconnectServer;
//We will automatically reconnect the subtitle service when the network is restored
- (void)reconnectedServer;
@end

@interface SpeechRecognModel : NSObject
+ (SpeechRecognModel *)sharedObject;
@property (strong,nonatomic) NSString *userNumberId;
@property (strong,nonatomic) NSString *appId;
@property (strong,nonatomic) NSString *authToken;
@property (strong,nonatomic) NSString *refreshToken;
@property (strong,nonatomic) NSString *bzid;
@property (assign,nonatomic) BOOL autoConnect;//It is recommended to open it so that the subtitle sdk can be automatically connected when the network is disconnected
@property (weak,nonatomic) id<FeloSubtitleDelegate> delegate;
/// GET MQTT INFO
/// @param clientType WEB、DESKTOP、IOS、ANDROID
/// @param completeHandler completeHandler description
- (void)getMqttInfo:(NSString *)clientType completeHandler:(void (^)(NSDictionary *))completeHandler;

/// get auth token for userid
/// @param userID userID description
- (void)getAuthToken:(NSString *)userID completeHandler:(void(^)(NSDictionary *))completeHandler;


- (void)refreshToken:(NSString *)grant_type  completeHandler:(void (^)(NSDictionary *))completeHandler;

/// Description
/// @param bizId bizId description
/// @param language language description
/// @param completeHandler completeHandler description
- (void)createConversation:(NSString *)bizId language:(NSString *)language completeHandler:(void (^)(BOOL ))completeHandler;

/// get conversation
/// @param bizId <#bizId description#>
/// @param completeHandler <#completeHandler description#>
- (void)getConversation:(NSString *)bizId  completeHandler:(void (^)(NSDictionary *))completeHandler;

- (void)joinConversation:(NSString *)bizId  completeHandler:(void (^)(NSDictionary *))completeHandler;

- (void)leaveConversation:(NSString *)bizId  completeHandler:(void (^)(BOOL flag))completeHandler;

- (void)setLanguage:(NSString *)bizId  language:(NSString *)language completeHandler:(void (^)(BOOL))completeHandler;


@end


