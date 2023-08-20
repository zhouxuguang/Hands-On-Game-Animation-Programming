//
//  Util.c
//  chapter01
//
//  Created by zhouxuguang on 2023/8/19.
//

#include "Util.h"
#import <AppKit/AppKit.h>
#include <mach/mach_time.h>
#include <CoreGraphics/CoreGraphics.h>

void *getApplication()
{
    NSApplication* application = [NSApplication sharedApplication];
    return application;
}

uint64_t GetTickCount()
{
    static mach_timebase_info_data_t timebase;
    
    if (timebase.denom == 0) {
        mach_timebase_info(&timebase);
    }
    
    uint64_t currentTime = mach_absolute_time();
    uint64_t elapsedTime = currentTime * timebase.numer / timebase.denom / 1000000;
    
    return elapsedTime;
}

float GetDevicePixelRatio()
{
    // 获取主显示器的屏幕 ID
    CGDirectDisplayID displayId = kCGDirectMainDisplay;
  
    // 获取设备像素比例
    CGDisplayModeRef mode = CGDisplayCopyDisplayMode(displayId);
    CGFloat pixelWidth = CGDisplayModeGetPixelWidth(mode);
    CGFloat width = CGDisplayModeGetWidth(mode);
  
    float devicePixelRatio = pixelWidth / width;
  
    CGDisplayModeRelease(mode);

    return devicePixelRatio;
}
