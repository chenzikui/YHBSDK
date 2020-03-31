//
//  YHBDeviceInfo.h
//  YHBSDK
//
//  Created by 陈自奎 on 2019/11/14.
//  Copyright © 2019 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YHBBlueTooth.h"

NS_ASSUME_NONNULL_BEGIN

@interface YHBDeviceInfo : NSObject

//单列初始化
+ (instancetype)manager;

//获取设备信息
-(NSDictionary *)getDeviceInfo;

//获取加速计信息
-(NSDictionary *)getAccelerationInfo;

//获取加速计信息
-(NSDictionary *)getGyroscopeInfo;

@end

NS_ASSUME_NONNULL_END
