//
//  SpeechRecognModel.m
//  Felo
//
//  Created by Felo on 2021/12/5.
//  Copyright © 2022 Sparticle inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface SpeechRecognModel : NSObject
+ (SpeechRecognModel *)sharedObject;
@property (strong,nonatomic) NSNumber *userNumberId;

- (void) startRecognize:(NSString *) meetingId language:(NSString *)language;
- (void) stopRecognize:(NSString *) meetingId;
- (void) initSpeechConfig;
- (void) startSpeaking:(NSString *)meetId :(NSString *)conversationId :(NSString *) speechRecoLang;
- (void) stopSpeaking:(NSString *)meetId :(NSString *)conversationId :(NSString *) speechRecoLang;
- (void) turnOnSubtitle:(NSString *)meetId :(NSString *)conversationId :(NSString *)speechRecoLang :(NSString *)translateToLanguage;
- (void) turnOffSubtitle:(NSString *)meetId :(NSString *)conversationId;
- (void) onMeetingSubtitleOn:(NSString *)meetId :(NSString *)conversationId :(NSString *) speechRecoLang;
- (void) onMeetingSubtitleOff:(NSString *)meetId :(NSString *)conversationId;
@end


