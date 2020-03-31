//
//  YHBHttpRequest.h
//  YHBSDK
//
//  Created by 陈自奎 on 2020/1/14.
//  Copyright © 2020 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YHBDefines.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^YHBRequestBlock)(NSDictionary * _Nullable response, NSError * _Nullable error);


@interface YHBHttpRequest : NSObject


//post 请求
-(void)postRequestUrlString:(NSString *)url params:(NSDictionary *)param block:(YHBRequestBlock)block;

//post 上传请求
-(void)uploadRequestUrlString:(NSString *)url params:(NSDictionary *)param headerParams:(NSDictionary *)headerParams formData:(NSDictionary *)formData block:(YHBRequestBlock)block;

@end

NS_ASSUME_NONNULL_END
