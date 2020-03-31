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
@property(nonatomic,assign)BOOL locationEnabled;//定位权限是否打开
//单列初始化
+ (instancetype)manager;

//获取一次定位信息
-(void)getOnceLocationInfo:(LocationBlock)block;

//持续获取一次定位信息
-(void)getAlwaysLocationInfo:(LocationBlock)block;

@end

NS_ASSUME_NONNULL_END
