//
//  TKDataSource.m
//  TableKitDemo
//
//  Created by Matthew Purland  on 8/20/13.
//
//

#import "TKDataSource.h"

@interface TKDataSource () {
    id<TKModel> _model;
}

@end

@implementation TKDataSource

- (instancetype) initWithModel: (id<TKModel>) model {
    self = [super init];
    
    if (!self) {
        return nil;
    }
    
    _model = model;
    
    return self;
}

- (id<TKModel>) model {
    return _model;
}

- (UIView *) viewForError: (NSError *) error {
    return _viewForError;
}

@end
