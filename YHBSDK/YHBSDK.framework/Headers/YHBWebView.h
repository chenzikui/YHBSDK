//
//

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>


//webview请求方式
typedef enum
{
    RequestToken = 0, //token模式
    RequestTicket = 1, //ticket模式
    RequestDev = 2, //本地开发模式
    RequestNone = 3,// 全链接Url模式
} RequestType;

@protocol YHBWebViewDelegate <NSObject>
@optional
- (BOOL)YHBWebView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)YHBWebViewDidFinishLoad:(UIWebView *)webView;
- (void)YHBWebViewDidStartLoad:(UIWebView *)webView;
- (void)YHBWebView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end

@interface YHBWebView : UIWebView
@property (nonatomic, weak) id<YHBWebViewDelegate> YHBdelegate;
@property (nonatomic, assign) BOOL is_debug; //是否开启测试环境 默认不开启
@property (nonatomic, strong) JSContext *context;

/*
   type  枚举 web请求方式
*/
- (instancetype)initWithFrame:(CGRect)frame WithType:(RequestType)type;

/*
   requestStr 字符串  前端获取的token、ticket
   extra: 字典
   @{
       @"channel":@"",  渠道号 string
       @"phone":@"",  用户手机号 string
   }
*/
-(void)requestWebWithReqstr:(NSString *)reqStr extra:(NSDictionary *)extra;
/*
   reqUrl 字符串  完整的请求连接
   extra: 字典
   @{
       @"channel":@"",  渠道号 string
       @"phone":@"",  用户手机号 string
   }
*/
-(void)requestWebWithReqUrl:(NSString *)reqUrl extra:(NSDictionary *)extra;

@end
