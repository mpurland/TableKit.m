//
//  TKFilterable.m
//  TableKitDemo
//
//  Created by Matthew Purland  on 8/20/13.
//
//

#import "TKFilterable.h"

@implementation TKFilterable

- (void) applyFilter: (id<TKFilter>) filter {
    [self willChangeValueForKey:NSStringFromSelector(@selector(filter))];
    _filter = filter;
    [self didChangeValueForKey:NSStringFromSelector(@selector(filter))];
}

@end
