//
//  LuaExports.h
//  Givit
//
//  Created by Sean Meiners on 2013/11/19.
//
//

#ifndef LUA_EXPORT_TYPE
    #define LUA_EXPORT_TYPE LuaExport
#endif

/**
 If an object of a type other than NSNull, NSNumber, NSString, NSArray, and NSDictionary is passed into a
 LuaContext it will, by default, appear as an opaque object. If you wish to call its methods or access any
 of its properties you will need to first derive a protocol from this which declares the properties and methods
 that should be accessible and then create a category which implements your protocol.

 For example, to allow your Lua script to control a UIView:

    @protcol UIViewLuaExports <LUA_EXPORT_TYPE>

    @property(nonatomic) CGFloat alpha;
    @property(nonatomic) CGRect bounds;
    @property(nonatomic) CGPoint center;
    @property(nonatomic) CGRect frame;

    // this can be called from Lua as view1.addSubview(view2)
    - (void)addSubview:(UIView*)view;
    // this can be called from Lua as view1.insertSubviewAboveSubview(view2, siblingSubview)
    - (void)insertSubview:(UIView *)view aboveSubview:(UIView *)siblingSubview;
    // this can be called from Lua as view1.insertSubviewBelowSubview(view2, siblingSubview)
    - (void)insertSubview:(UIView *)view belowSubview:(UIView *)siblingSubview;
    - (void)removeFromSuperview;

    @end

    @interface UIView (UIViewLuaExports) <UIViewLuaExports>
    @end
    @implementation UIView (UIViewLuaExports)
    @end
 */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wduplicate-protocol"

@protocol LUA_EXPORT_TYPE
@end

#pragma clang diagnostic pop
