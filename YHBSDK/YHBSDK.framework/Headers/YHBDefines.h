//
//  YHBDefines.h
//  YHBSDK
//
//  Created by 陈自奎 on 2019/11/18.
//  Copyright © 2019 陈自奎. All rights reserved.
//

#ifndef YHBDefines_h
#define YHBDefines_h

//屏幕宽高
#define YHBScreenW [UIScreen mainScreen].bounds.size.width
#define YHBScreenH [UIScreen mainScreen].bounds.size.height

//__weak self 定义
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

//是否为空或是[NSNull null]
#define NotNilAndNull(_ref)  (((_ref) != nil) && (![(_ref) isEqual:[NSNull null]]))
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))

//字符串是否为空
#define IsStrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref)isEqualToString:@""]))
//数组是否为空
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) count] == 0))
//字符串为空默认空串
#define VALIDATE_STRING(str) (IsNilOrNull(str) ? @"" : str)


#endif /* YHBDefines_h */
