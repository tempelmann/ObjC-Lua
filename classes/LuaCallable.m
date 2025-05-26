//
//  LuaCallable.m
//  LuaTests
//
//  Created by Brian Pedersen on 03/08/2024.
//  Copyright © 2024 Sean Meiners. All rights reserved.
//

#import "LuaCallable.h"
#import "LuaContext.h"

@implementation LuaCallable

- (id)initWithState:(lua_State *)L index:(int)index {
    lua_pushvalue(L, index);
    lua_Integer ref = luaL_ref(L, LUA_REGISTRYINDEX);
    if (self = [super init]) {
        _handle = (int) ref;
        _L = L;
    } else {
        _L = NULL;
    }
    return self;
}

- (void)dealloc {
    [self destroy];
}

- (void)destroy {
    if (_L) {
        lua_State *L = _L;
        _L = NULL;
        luaL_unref(L, LUA_REGISTRYINDEX, (int)_handle);
    }
}

- (NSString *)description {
    return [NSString stringWithFormat:@"Anonymous callable object with handle %d",_handle];
}

- (NSString *)debugDescription {
    return [self description];
}

@end
