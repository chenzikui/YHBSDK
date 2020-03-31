//
//  TestVideoViewController.h
//  Memento
//
//  Created by Ömer Faruk Gül on 22/05/15.
//  Copyright (c) 2015 Ömer Faruk Gül. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YHBComMacro.h"

typedef void(^YHBVedioVCBlock)(BOOL isUse);

@interface YHBVideoViewController : UIViewController

@property(nonatomic,strong)YHBVedioVCBlock block;

- (instancetype)initWithVideoUrl:(NSURL *)url;

@end
