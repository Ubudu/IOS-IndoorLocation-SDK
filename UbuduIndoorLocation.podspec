Pod::Spec.new do |s|
  s.name         = "UbuduIndoorLocation"
  s.version      = "2.5.1"
  s.summary      = "Indoor Location SDK allows real time indoor positioning and navigation with beacons."
  s.homepage     = "http://www.ubudu.com"
  s.license      = { :type => "BSD", :file => "LICENSE" }
  s.author       = { "Ubudu SAS" => "cocoapods@ubudu.com" }
  s.social_media_url = "https://twitter.com/Ubudu"

  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/Ubudu/IOS-IndoorLocation-SDK.git", :tag => "v2.5.1" }
  s.vendored_frameworks = "UbuduIndoorLocation.framework"
  s.frameworks = "Foundation", "CoreGraphics", "UIKit", "CoreLocation"
  s.libraries = "c++"

  s.requires_arc = true
  s.xcconfig = { "OTHER_LDFLAGS" => "" }
end
