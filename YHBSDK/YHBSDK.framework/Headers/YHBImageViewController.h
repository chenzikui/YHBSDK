//
//  ImageViewController.h
//  YHBSimpleCameraExample
//
//  Created by Ömer Faruk Gül on 15/11/14.
//  Copyright (c) 2014 Ömer Faruk Gül. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YHBComMacro.h"

typedef void(^YHBImageVCBlock)(BOOL isUse);


@interface YHBImageViewController : UIViewController

@property(nonatomic,strong)YHBImageVCBlock block;

- (instancetype)initWithImage:(UIImage *)image;

@end
