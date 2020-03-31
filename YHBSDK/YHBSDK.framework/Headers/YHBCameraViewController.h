//
//  HomeViewController.h
//  YHBSimpleCameraExample
//
//  Created by Ömer Faruk Gül on 29/10/14.
//  Copyright (c) 2014 Ömer Faruk Gül. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YHBSimpleCamera.h"
#import "YHBComMacro.h"
#import "YHBCommon.h"

typedef NS_ENUM(NSInteger, YHBCameraScoreType) {
    YHBCameraScoreImageTypeFront = 0,//拍照 前置
    YHBCameraScoreImageTypeBack,//拍照 后置
    YHBCameraScoreAlbumType,//相册
    YHBCameraScoreVideoTypeFront,//录制视频 前置
    YHBCameraScoreVideoTypeBack,//录制视频 后置
};


@protocol YHBCameraViewControllerDelegate <NSObject>

-(void)didCameraError;

//摄像头拍照图片 回传base64给h5
-(void)didCameraFinishedWithImage:(UIImage *)image;

//摄像头录制视频上传
-(void)didCameraFinishedWithVedio:(NSURL *)filePath;

//摄像头捕获图片静默上传
-(void)didCameraCatchBufferImage:(UIImage *)image;

//摄像头controller关闭
-(void)didCameraViewClose;


@end


@interface YHBCameraViewController : UIViewController

@property (nonatomic, assign)YHBCameraScoreType sourceType;
@property (nonatomic, assign)BOOL canEdit; //是否可以编辑 默认不可
@property (nonatomic, assign)BOOL showContrllers; //是否展示原生控件
@property (nonatomic, assign)YHBCameraFaceType faceType; //活体类型
@property (nonatomic, weak)id<YHBCameraViewControllerDelegate> vc_delegate; 

- (void)cameraStartAction;
- (void)cameraStopAction;
- (void)switchPressed;
- (void)flashPressed;
- (void)closeVC;
- (void)cameraAutoPhoto;

@end
