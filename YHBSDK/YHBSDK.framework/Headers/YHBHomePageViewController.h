//
//  YHBHomePageViewController.h
//  YHBSDK
//
//  Created by 陈自奎 on 2019/9/30.
//  Copyright © 2019 陈自奎. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YHBSignFile.h"
#import "YHBWebView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YHBHomePageViewController : UIViewController
@property (strong, nonatomic) YHBWebView *webView;

+(instancetype)setupPageVC;

/*
    开启测试模式
    此方法需在初始化web之前使用
*/
-(void)openDebugModel;

/*
    type  枚举 web请求方式
    requestStr 字符串  前端获取的token、ticket
    extra: 字典
    @{
       @"channel":@"",  渠道号 string
       @"phone":@"",  用户手机号 string
    }
*/
-(void)setupWebithType:(RequestType)type reqstr:(NSString *)reqStr extra:(NSDictionary *)extra;

@end

NS_ASSUME_NONNULL_END
