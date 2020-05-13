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

/*
    webview
*/
@property (strong, nonatomic) YHBWebView *webView;

+(instancetype)setupPageVC;

/*
    开启测试模式
    此方法需在初始化web之前使用
    只针对token方式和ticket方式
*/
-(void)openDebugModel;

/*
    是否开启第一次加载的进度条
*/
-(void)showWebviewProgress;

/*
    type  枚举 web请求方式
    reqStr 字符串  前端获取的token、ticket
    extra: 字典 校验参数
    @{
       @"channel":@"",  渠道号 string
       @"phone":@"",  用户手机号 string
    }
*/
-(void)setupWebWithType:(RequestType)type reqStr:(NSString *)reqStr extra:(NSDictionary *)extra;


/*
    type  枚举 web请求方式
    reqUrl 字符串  完整的请求连接
    extra: 字典 校验参数
    @{
       @"channel":@"",  渠道号 string
       @"phone":@"",  用户手机号 string
    }
*/
-(void)setupWebWithReqUrl:(NSString *)reqUrl extra:(NSDictionary *)extra;

@end

NS_ASSUME_NONNULL_END
