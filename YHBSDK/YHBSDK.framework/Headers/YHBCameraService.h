//
//  YHBCameraService.h
//  YHBSDK
//
//  Created by 陈自奎 on 2020/1/8.
//  Copyright © 2020 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YHBCommon.h"
#import "YHBCameraViewController.h"
#import "YHBWebView.h"
#import "YHBCameraModel.h"


typedef void(^YHBCameraBlock)(NSDictionary * _Nullable dic);

NS_ASSUME_NONNULL_BEGIN

@interface YHBCameraService : NSObject

/*
    webview
*/
@property (strong, nonatomic) YHBWebView *webView;

@property (nonatomic, strong)YHBCameraViewController *cameraVC;

+ (instancetype _Nullable )manager;

- (void)startCameraWithVC:(UIViewController *_Nonnull)sourceVC
                 model:(YHBCameraModel *)model
                 success:(YHBCameraBlock _Nullable )success
                 failure:(YHBCameraBlock _Nonnull )failure;

- (void)cameraStartAction;
- (void)cameraStopAction;
- (void)switchPressed;
- (void)flashPressed;
- (void)closeVC;
- (void)cameraAutoPhoto;

//相机权限是否开启
-(BOOL)isCanUseCamera;
//相册权限是否开启
-(BOOL)isCanUsePhotos;
//麦克风权限是否开启
-(BOOL)isCanUseMicrophone;

@end

NS_ASSUME_NONNULL_END
