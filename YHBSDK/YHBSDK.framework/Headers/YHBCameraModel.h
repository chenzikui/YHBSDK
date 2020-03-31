//
//  YHBCameraModel.h
//  YHBSDK
//
//  Created by 陈自奎 on 2020/1/9.
//  Copyright © 2020 陈自奎. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YHBCameraViewController.h"

NS_ASSUME_NONNULL_BEGIN


@interface YHBCameraModel : NSObject

@property(nonatomic,copy)NSString *type;
@property(nonatomic,copy)NSString *action;
@property(nonatomic,copy)NSString *path;
@property(nonatomic,strong)NSString *quality;//图片质量
@property(nonatomic,strong)NSString *data;//回传的校验数据

@property(nonatomic,strong)NSDictionary *params;//请求校验参数
@property(nonatomic,strong)NSDictionary *headerParams;
@property(nonatomic,strong)NSString *uploadPath;//视频上传路径
@property(nonatomic,strong)NSString *picUploadPath;//图片上传路径
@property(nonatomic,strong)NSString *faceType;//活体类型 nmber 数字活体 action 动作活体




@property(nonatomic,assign)int count; //选择图片数量 默认为1

@property(nonatomic,assign)BOOL canEdit;
@property(nonatomic,assign)BOOL push;
@property(nonatomic,assign)BOOL showControllers;

@property (nonatomic, assign)YHBCameraScoreType sourceType;


-(void)setupModelData:(NSDictionary *)dic;


@end

NS_ASSUME_NONNULL_END
