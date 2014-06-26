//
//  NSArray+TableKit.m
//  TableKitDemo
//
//  Created by Matthew Purland on 9/12/13.
//
//

#import "NSArray+TableKit.h"
#import "NSObject+TableKit.h"

@implementation NSArray (TableKit)

- (void)perform:(SEL)selector {
    NSArray *copy = [[NSArray alloc] initWithArray:self];
    NSEnumerator* e = [copy objectEnumerator];
    for (id delegate; (delegate = [e nextObject]); ) {
        if ([delegate respondsToSelector:selector]) {
            SuppressPerformSelectorLeakWarning(
                [delegate performSelector:selector];
            );
        }
    }
}

- (void)perform:(SEL)selector withObject:(id)p1 {
    NSArray *copy = [[NSArray alloc] initWithArray:self];
    NSEnumerator* e = [copy objectEnumerator];
    for (id delegate; (delegate = [e nextObject]); ) {
        if ([delegate respondsToSelector:selector]) {
            SuppressPerformSelectorLeakWarning(
                [delegate performSelector:selector withObject:p1];
            );
        }
    }
}

- (void)perform:(SEL)selector withObject:(id)p1 withObject:(id)p2 {
    NSArray *copy = [[NSArray alloc] initWithArray:self];
    NSEnumerator* e = [copy objectEnumerator];
    for (id delegate; (delegate = [e nextObject]); ) {
        if ([delegate respondsToSelector:selector]) {
            SuppressPerformSelectorLeakWarning(
                [delegate performSelector:selector withObject:p1 withObject:p2];
            );
        }
    }
}

- (void)perform:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3 {
    NSArray *copy = [[NSArray alloc] initWithArray:self];
    NSEnumerator* e = [copy objectEnumerator];
    for (id delegate; (delegate = [e nextObject]); ) {
        if ([delegate respondsToSelector:selector]) {
            SuppressPerformSelectorLeakWarning(
                [delegate performSelector:selector withObject:p1 withObject:p2 withObject:p3];
            );
        }
    }
}

- (void)makeObjectsPerformSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 {
    for (id delegate in self) {
        SuppressPerformSelectorLeakWarning(
            [delegate performSelector:selector withObject:p1 withObject:p2];
        );
    }
}

- (void)makeObjectsPerformSelector: (SEL)selector
                        withObject: (id)p1
                        withObject: (id)p2
                        withObject: (id)p3 {
    for (id delegate in self) {
        [delegate performSelector:selector withObject:p1 withObject:p2 withObject:p3];
    }
}

@end
