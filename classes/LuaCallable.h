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

@interface LuaCallable : NSObject

@property (readonly) lua_Integer handle;
@property (readonly,assign) lua_State *L;

-(id)initWithHandle:(lua_Integer)handle context:(lua_State *)L;

@end

NS_ASSUME_NONNULL_END
