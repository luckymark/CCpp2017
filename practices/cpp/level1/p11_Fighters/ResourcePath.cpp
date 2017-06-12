#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GAME.h"
#include "PLAYERS.h"
#include <vector>
#include "bullet.h"
#include "enemys.h"
#include <cmath>
#include "RESOURCE.h"
#include <time.h>
#include "TEXTURE.h"
#include "ResourcePath.h"
#import <Foundation/Foundation.h>

std::string resourcePath(void)
{
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

	std::string rpath;
	NSBundle* bundle = [NSBundle mainBundle];

	if (bundle == nil) {
#ifdef DEBUG
		NSLog(@"bundle is nil... thus no resources path can be found.");
#endif
	}
	else {
		NSString* path = [bundle resourcePath];
		rpath = [path UTF8String] + std::string("/");
	}

	[pool drain];

	return rpath;
}