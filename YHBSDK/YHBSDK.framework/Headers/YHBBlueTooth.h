//
//  YHBBlueTooth.h
//  YHBSDK
//
//  Created by 陈自奎 on 2019/12/31.
//  Copyright © 2019 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <YHBSDK/YHBDefines.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHBBlueTooth : NSObject<CBCentralManagerDelegate>

//单列初始化
+ (instancetype)manager;


//开始扫描
-(void)startScaning;

//停止扫描
-(void)stopScaning;


//获取当前蓝牙列表
-(NSArray *)getBlueToothList;

@property (nonatomic, strong) CBCentralManager *centralManager;
@property (nonatomic, assign) BOOL BTEnable;//蓝牙是否可用


@end

NS_ASSUME_NONNULL_END
