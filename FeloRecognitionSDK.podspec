Pod::Spec.new do |spec|
  spec.name         = "FeloRecognitionSDK"
  spec.version      = "1.0.0"
  spec.summary      = "An Objective-C client for Speech Recognition service"

  spec.description  = 'Speech Recognition Voice Translate Recognition Translation'
  spec.homepage     = "https://github.com/sparticleinc/FeloRecognitionSdk"

  spec.license      = "MIT (LICENSE.md)"
  spec.author             = { "lee.zhu" => "lee.zhu@sparticle.com" }
  spec.platform     = :ios, "11.0"
  spec.source       = { :git => "https://github.com/sparticleinc/FeloRecognitionSdk.git", :tag => spec.version}
  spec.vendored_frameworks = "FeloRecognitionSDK.framework"
  spec.requires_arc = true
  spec.ios.libraries = "c"
  spec.framework  = "Foundation"
  spec.xcconfig = {
  'VALID_ARCHS' =>  'arm64'
}
end
