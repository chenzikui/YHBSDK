//
//  YHBImagePickerController.h
//  YHBImagePicker
//
//  Created by LEA on 2017/3/2.
//  Copyright © 2017年 LEA. All rights reserved.
//
//  图库列表
//

#import <UIKit/UIKit.h>
#import "YHBImageCropController.h"
#import "YHBImagePickerMacros.h"

#pragma mark - ################## YHBImagePickerController
@protocol YHBImagePickerDelegate;
@interface YHBImagePickerController : UIViewController

// 主色调[默认蓝色]
@property (nonatomic, strong) UIColor * mainColor;
// 是否回传原图[可用于控制图片压系数]
@property (nonatomic, assign) BOOL isOrigin;
// 是否显示原图选项[默认NO]
@property (nonatomic, assign) BOOL showOriginImageOption;
// 是否只选取一张[默认NO]
@property (nonatomic, assign) BOOL singleImageOption;
// 是否选取一张且需要裁剪[默认NO]
@property (nonatomic, assign) BOOL cropImageOption;
// 裁剪的大小[默认方形、屏幕宽度]
@property (nonatomic, assign) CGSize imageCropSize;
// 最大选择数目[默认9张]
@property (nonatomic, assign) NSInteger maximumNumberOfImage;
// 代理
@property (nonatomic, assign) id<YHBImagePickerDelegate> delegate;

@end

@protocol YHBImagePickerDelegate <NSObject>

@optional
/**
 info释义:
 返回的媒体数据是数组，数组单元为字典，字典中包含以下数据：
 
 资源类型 ALAssetPropertyType
 位置方向 ALAssetPropertyLocation
 原始图片 UIImagePickerControllerOriginalImage
 原件路径 UIImagePickerControllerReferenceURL
 
 */
- (void)YHBImagePickerController:(YHBImagePickerController *)picker didFinishPickingMediaWithInfo:(NSArray<NSDictionary *> *)info;
- (void)YHBImagePickerControllerDidCancel:(YHBImagePickerController *)picker;

@end

#pragma mark - ################## YHBAlbumCell
@interface YHBAlbumCell : UITableViewCell

@end
