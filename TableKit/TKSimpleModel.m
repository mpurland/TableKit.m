//
//  TKSimpleModel.m
//  TableKitDemo
//
//  Created by Matthew Purland on 9/12/13.
//
//

#import "TKSimpleModel.h"

@interface TKSimpleModel ()

@property (nonatomic, assign) BOOL loaded;

@end

@implementation TKSimpleModel

- (instancetype) initWithItems: (NSArray *) items {
    self = [super init];
    
    if (!self) {
        return nil;
    }
    
    self.items = items;
    
    return self;
}

- (void) load:(TKModelLoadType)loadType {
    [super load:loadType];
    _loaded = YES;
}

- (void) invalidate: (BOOL) erase {
    _loaded = NO;
    
    if (erase) {
        self.items = nil;
    }
}

@end
