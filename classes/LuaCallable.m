//
//  LuaCallable.m
//  LuaTests
//
//  Created by Brian Pedersen on 03/08/2024.
//  Copyright © 2024 Sean Meiners. All rights reserved.
//

#import "LuaCallable.h"

@implementation LuaCallable

- (id)initWithHandle:(lua_Integer)handle context:(lua_State *)L {
    if (self = [super init]) {
        _handle = handle;
        _L = L;
    } else {
        _L = NULL;
    }
    return self;
}

- (void)dealloc {
    if (_L != NULL) {
        luaL_unref(_L, LUA_REGISTRYINDEX, (int)_handle);
        _L = NULL;
    }
}

- (NSString *)description {
    return [NSString stringWithFormat:@"Anonymous callable object with handle %lld",_handle];
}

- (NSString *)debugDescription {
    return [self description];
}

@end
