//
//  CameraViewController.h
//  YHBSimpleCamera
//
//  Created by Ömer Faruk Gül on 24/10/14.
//  Copyright (c) 2014 Ömer Farul Gül. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

typedef enum : NSUInteger {
    YHBCameraPositionRear,
    YHBCameraPositionFront
} YHBCameraPosition;

typedef enum : NSUInteger {
    // The default state has to be off
    YHBCameraFlashOff,
    YHBCameraFlashOn,
    YHBCameraFlashAuto
} YHBCameraFlash;

typedef enum : NSUInteger {
    // The default state has to be off
    YHBCameraMirrorOff,
    YHBCameraMirrorOn,
    YHBCameraMirrorAuto
} YHBCameraMirror;

typedef NS_ENUM(NSInteger, YHBCameraFaceType) {
    YHBFaceTypeNumber = 0,//数字活体
    YHBFaceTypeAction,//动作活体
};

extern NSString *const YHBSimpleCameraErrorDomain;
typedef enum : NSUInteger {
    YHBSimpleCameraErrorCodeCameraPermission = 10,
    YHBSimpleCameraErrorCodeMicrophonePermission = 11,
    YHBSimpleCameraErrorCodeSession = 12,
    YHBSimpleCameraErrorCodeVideoNotEnabled = 13
} YHBSimpleCameraErrorCode;

@interface YHBSimpleCamera : UIViewController

/**
 * Triggered on device change.
 */
@property (nonatomic, copy) void (^onDeviceChange)(YHBSimpleCamera *camera, AVCaptureDevice *device);

/**
 * Triggered on any kind of error.
 */
@property (nonatomic, copy) void (^onError)(YHBSimpleCamera *camera, NSError *error);

/**
 * Triggered when camera starts recording
 */
@property (nonatomic, copy) void (^onStartRecording)(YHBSimpleCamera* camera);

/**
 * Camera quality, set a constants prefixed with AVCaptureSessionPreset.
 * Make sure to call before calling -(void)initialize method, otherwise it would be late.
 */
@property (copy, nonatomic) NSString *cameraQuality;

/**
 * Camera flash mode.
 */
@property (nonatomic, readonly) YHBCameraFlash flash;

/**
 * Camera mirror mode.
 */
@property (nonatomic) YHBCameraMirror mirror;

/**
 * Position of the camera.
 */
@property (nonatomic) YHBCameraPosition position;

/**
 * White balance mode. Default is: AVCaptureWhiteBalanceModeContinuousAutoWhiteBalance
 */
@property (nonatomic) AVCaptureWhiteBalanceMode whiteBalanceMode;

/**
 * Boolean value to indicate if the video is enabled.
 */
@property (nonatomic, getter=isVideoEnabled) BOOL videoEnabled;

/**
 * Boolean value to indicate if the camera is recording a video at the current moment.
 */
@property (nonatomic, getter=isRecording) BOOL recording;

/**
 * Boolean value to indicate if zooming is enabled.
 */
@property (nonatomic, getter=isZoomingEnabled) BOOL zoomingEnabled;

/**
 * Float value to set maximum scaling factor
 */
@property (nonatomic, assign) CGFloat maxScale;

/**
 * Fixess the orientation after the image is captured is set to Yes.
 * see: http://stackoverflow.com/questions/5427656/ios-uiimagepickercontroller-result-image-orientation-after-upload
 */
@property (nonatomic) BOOL fixOrientationAfterCapture;

/**
 * Set NO if you don't want ot enable user triggered focusing. Enabled by default.
 */
@property (nonatomic) BOOL tapToFocus;

/**
 * Set YES if you your view controller does not allow autorotation,
 * however you want to take the device rotation into account no matter what. Disabled by default.
 */
@property (nonatomic) BOOL useDeviceOrientation;

/**
 * Use this method to request camera permission before initalizing YHBSimpleCamera.
 */
+ (void)requestCameraPermission:(void (^)(BOOL granted))completionBlock;

/**
 * Use this method to request microphone permission before initalizing YHBSimpleCamera.
 */
+ (void)requestMicrophonePermission:(void (^)(BOOL granted))completionBlock;

/**
 * Returns an instance of YHBSimpleCamera with the given quality.
 * Quality parameter could be any variable starting with AVCaptureSessionPreset.
 */
- (instancetype)initWithQuality:(NSString *)quality position:(YHBCameraPosition)position videoEnabled:(BOOL)videoEnabled;

/**
 * Returns an instance of YHBSimpleCamera with quality "AVCaptureSessionPresetHigh" and position "CameraPositionBack".
 * @param videEnabled: Set to YES to enable video recording.
 */
- (instancetype)initWithVideoEnabled:(BOOL)videoEnabled;

/**
 * Starts running the camera session.
 */
- (void)start;

/**
 * Stops the running camera session. Needs to be called when the app doesn't show the view.
 */
- (void)stop;


/**
 * Capture an image.
 * @param onCapture a block triggered after the capturing the photo.
 * @param exactSeenImage If set YES, then the image is cropped to the exact size as the preview. So you get exactly what you see.
 * @param animationBlock you can create your own animation by playing with preview layer.
 */
-(void)capture:(void (^)(YHBSimpleCamera *camera, UIImage *image, NSDictionary *metadata, NSError *error))onCapture exactSeenImage:(BOOL)exactSeenImage animationBlock:(void (^)(AVCaptureVideoPreviewLayer *))animationBlock;

/**
 * Capture an image.
 * @param onCapture a block triggered after the capturing the photo.
 * @param exactSeenImage If set YES, then the image is cropped to the exact size as the preview. So you get exactly what you see.
 */
-(void)capture:(void (^)(YHBSimpleCamera *camera, UIImage *image, NSDictionary *metadata, NSError *error))onCapture exactSeenImage:(BOOL)exactSeenImage;

/**
 * Capture an image.
 * @param onCapture a block triggered after the capturing the photo.
 */
-(void)capture:(void (^)(YHBSimpleCamera *camera, UIImage *image, NSDictionary *metadata, NSError *error))onCapture;

/*
 * Start recording a video with a completion block. Video is saved to the given url.
 */
- (void)startRecordingWithOutputUrl:(NSURL *)url didRecord:(void (^)(YHBSimpleCamera *camera, NSURL *outputFileUrl, NSError *error))completionBlock;

/**
 * Stop recording video.
 */
- (void)stopRecording;

/**
 * Attaches the YHBSimpleCamera to another view controller with a frame. It basically adds the YHBSimpleCamera as a
 * child vc to the given vc.
 * @param vc A view controller.
 * @param frame The frame of the camera.
 */
- (void)attachToViewController:(UIViewController *)vc withFrame:(CGRect)frame;

/**
 * Changes the posiition of the camera (either back or front) and returns the final position.
 */
- (YHBCameraPosition)togglePosition;

/**
 * Update the flash mode of the camera. Returns true if it is successful. Otherwise false.
 */
- (BOOL)updateFlashMode:(YHBCameraFlash)cameraFlash;

/**
 * Checks if flash is avilable for the currently active device.
 */
- (BOOL)isFlashAvailable;

/**
 * Checks if torch (flash for video) is avilable for the currently active device.
 */
- (BOOL)isTorchAvailable;

/**
 * Alter the layer and the animation displayed when the user taps on screen.
 * @param layer Layer to be displayed
 * @param animation to be applied after the layer is shown
 */
- (void)alterFocusBox:(CALayer *)layer animation:(CAAnimation *)animation;

/**
 * Checks is the front camera is available.
 */
+ (BOOL)isFrontCameraAvailable;

/**
 * Checks is the rear camera is available.
 */
+ (BOOL)isRearCameraAvailable;

/**
* 图片捕获.
*/
-(void)getCamerBufferImage:(void (^)(UIImage *image)) bufferBlock;

//捕获图像和视频录制不可同时存在使用
-(void)addCameraBufferSession;
-(void)addCameraRecordSession;



@end
