//
//  YHBXWFintechApi.h
//  YHBSDK
//
//  Created by 陈自奎 on 2019/12/12.
//  Copyright © 2019 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <AudioToolbox/AudioToolbox.h>
#import "YHBWebviewBlockManger.h"

NS_ASSUME_NONNULL_BEGIN

@interface YHBXWFintechApi : NSObject

-(void)setupWithWebview:(UIWebView *)webview withJSContext:(JSContext *)context;

@end

NS_ASSUME_NONNULL_END
