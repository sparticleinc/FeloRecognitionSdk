//
//  SpeechRecognProtocol.h
//  FeloRecognition
//
//  Created by lee on 2022/10/8.
//

#import <Foundation/Foundation.h>

@protocol SpeechRecognProtocol <NSObject>

@required
- (void)getAccessToken:(NSString *)userId block:(void(^)(NSDictionary *))block;

@end
