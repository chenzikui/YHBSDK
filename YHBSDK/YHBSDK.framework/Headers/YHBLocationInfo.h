//
//  YHBLocationInfo.h
//  YHBSDK
//
//  Created by 陈自奎 on 2019/11/14.
//  Copyright © 2019 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^LocationBlock)(NSDictionary *option);

@interface YHBLocationInfo : NSObject<CLLocationManagerDelegate>

@property(nonatomic,strong)CLLocationManager *locationmanager;//定位服务

//单列初始化
+ (instancetype)manager;

//获取定位信息
-(void)getLocationInfo:(LocationBlock)block;


@end

NS_ASSUME_NONNULL_END
