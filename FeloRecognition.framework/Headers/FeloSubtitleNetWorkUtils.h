//
//  FeloSubtitleNetWorkUtils.h
//  FeloRecognition
//
//  Created by lee on 2022/9/7.
//

#import <Foundation/Foundation.h>

//@protocol FeloSubtitleNetWorkUtilsDelegate<NSObject>
//@required
//- (void)tokenIsExpired:(BOOL)isExpired;
//@end

@interface FeloSubtitleNetWorkUtils : NSObject
+(instancetype)manager;

//@property(weak,nonatomic)id<FeloSubtitleNetWorkUtilsDelegate> delegate;

@property(strong,nonatomic) NSString *appId;
@property(strong,nonatomic) NSString *authToken;
- (void)feloPost:(NSString *)url  parameters:(NSMutableDictionary *)parameters header:(NSString *)token successed:(void (^)(id responseObject))successed failed:(void (^)(NSError *error))failed;

- (void)feloMeetingGet:(NSString *)url  parameters:(NSMutableDictionary *)parameters successed:(void (^)(id responseObject))successed failed:(void (^)(NSError *error))failed;

- (void)feloGetToken:(NSString *)url successed:(void (^)(id responseObject))successed failed:(void (^)(NSError *error))failed;
- (BOOL)postSuccess:(NSDictionary *)data;

- (BOOL)tokenExpired:(NSDictionary *)data;
@end


