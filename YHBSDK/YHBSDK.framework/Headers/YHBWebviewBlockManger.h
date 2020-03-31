//
//  YHBWebviewBlockManger.h
//  YHBSDK
//
//  Created by 陈自奎 on 2020/3/19.
//  Copyright © 2020 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHBWebviewBlockManger : NSObject

+ (instancetype _Nullable )manager;

@property (nonatomic, strong) JSValue *verifyCallback;

@end

NS_ASSUME_NONNULL_END
