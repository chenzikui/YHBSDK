Pod::Spec.new do |spec|

spec.name         = "YHBSDK" #名称

spec.version      = "1.0.0" #版本号

spec.summary      = "YHBSDK SDK" #简介

spec.description  = "YHBSDK"#描述

spec.homepage     = "https://github.com/chenzikui/YHBSDK"#项目主页地址

spec.license      = "MIT"#许可证

spec.author             = { "chenzikui" => "czk19890516@qq.com" } #作者

# ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

spec.platform     = :ios, "9.0"  #支持最小系统版本

spec.source       = { :git => "https://github.com/chenzikui/YHBSDK.git", :tag => spec.version }  #项目的地址 （注意这里的tag位置，可以自己写也可以直接用s.version，但是与s.version一定要统一）

 

#spec.source_files  = 'YHBSDK/YHBSDK.framework/Headers/*.{h,m}'#需要包含的源文件（也是个坑）按照你的文件层级来

spec.vendored_frameworks = 'YHBSDK/YHBSDK.framework'  #你的SDK路径（因为传的是静态库，这个必须要）

 

spec.resources = "YHBSDK/YHBSDKBundle.bundle"

spec.frameworks = "Foundation", "UIKit"#依赖库

spec.dependency 'AFNetworking', '~> 3.2.1'

#依赖的第三方，有几个写几个

end