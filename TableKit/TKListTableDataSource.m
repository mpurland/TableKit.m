//
//  TKListTableDataSource.m
//  TableKitDemo
//
//  Created by Matthew Purland on 9/12/13.
//
//

#import "TKListTableDataSource.h"

@implementation TKListTableDataSource

- (instancetype) initWithItems: (NSArray *) items {
    self = [super init];
    
    if (!self) {
        return nil;
    }
    
    return self;
}

+ (instancetype) dataSourceWithItems: (NSArray *) items {
    return [[[self class] alloc] initWithItems: items];
}

@end
