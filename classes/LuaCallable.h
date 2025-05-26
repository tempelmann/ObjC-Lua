//
//  LuaCallable.h
//  LuaTests
//
//  Created by Brian Pedersen on 03/08/2024.
//  Copyright © 2024 Sean Meiners. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "lua.h"
#import "lauxlib.h"
#import "lualib.h"

NS_ASSUME_NONNULL_BEGIN

@class LuaContext;

@interface LuaCallable : NSObject

@property (readonly) int handle;
@property (readonly,assign) lua_State *L;

- (id)initWithState:(lua_State *)L index:(int)index;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
