//
//  Util.c
//  chapter01
//
//  Created by zhouxuguang on 2023/8/19.
//

#include "Util.h"
#import <AppKit/AppKit.h>

void *getApplication()
{
    NSApplication* application = [NSApplication sharedApplication];
    return application;
}
