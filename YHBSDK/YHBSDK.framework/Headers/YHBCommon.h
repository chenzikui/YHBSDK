//
//  Common.h
//  XHAudioPlayer
//
//  Created by icochu on 2019/6/13.
//  Copyright © 2019 Sniper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YHBSDK.h"


NS_ASSUME_NONNULL_BEGIN

@interface YHBCommon : NSObject

@property (nonatomic, assign) BOOL is_debug; //是否开启测试环境 默认不开启
@property (nonatomic, assign) RequestType requestType; //请求方式
@property(nonatomic,strong)NSString* curHost;//当前host

+ (instancetype)manager;

-(void)setRequestNoneHost:(NSString *)req;

//展示时间
- (void)updataTimerLableWithLable:(UILabel *)lable Second:(NSInteger)time;

//转换时间
- (NSString *)updataTimerLableWithSecond:(NSInteger)time;

@end

NS_ASSUME_NONNULL_END
