//
//  YHBSignFile.h
//  YHBSDK
//
//  Created by 陈自奎 on 2019/9/30.
//  Copyright © 2019 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHBSignFile : NSObject
/*
    dic:获取token时必传数据
    @{
        @"channel":@"",  渠道号 string
        @"phone":@"",  用户手机号 string
    }
 */
-(NSString *)getSignData:(NSDictionary *)dic;

/*
    JSON转字典
    jsonStr: json字符串 string
 */

-(NSDictionary *)convertDicWithJSON:(NSString *)jsonStr;

@end

NS_ASSUME_NONNULL_END
