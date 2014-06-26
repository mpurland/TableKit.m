//
//  TKModel.m
//  TableKitDemo
//
//  Created by Matthew Purland  on 8/20/13.
//
//

#import "TKModel.h"
#import "NSArray+TableKit.h"

@implementation TKModel
@synthesize delegates = _delegates;

- (void) load:(TKModelLoadType)loadType {
    // Does nothing by default
}

- (void) load {
    [self load:TKModelLoadTypeAll];
}

- (void) loadMore {
    [self load:TKModelLoadTypeMore];
}

- (void) cancel {
    
}

- (void) invalidate: (BOOL) erase {
    
}

- (BOOL) isLoaded {
    return YES;
}

- (BOOL) isLoading {
    return NO;
}

- (BOOL) isLoadingMore {
    return NO;
}

- (BOOL) isOutdated {
    return NO;
}

#pragma mark - Notify model delegate of events

- (void) modelDidStartLoad {
    [self.delegates makeObjectsPerformSelector:@selector(modelDidStartLoad:) withObject:self];
}

- (void) modelDidFinishLoad {
    [self.delegates makeObjectsPerformSelector:@selector(modelDidFinishLoad:) withObject:self];
}

- (void) modelDidFailLoadWithError: (NSError *) error {
    [self.delegates makeObjectsPerformSelector:@selector(model:didFailLoadWithError:) withObject:self withObject: error];
}

- (void) modelDidCancelLoad {
    [self.delegates makeObjectsPerformSelector:@selector(modelDidCancelLoad:) withObject:self];
}

- (void) modelDidInvalidateWithErase: (BOOL) erase {
    [self.delegates makeObjectsPerformSelector:@selector(modelDidInvalidateWithErase:) withObject:@(erase)];
}

- (void) modelDidChange {
    [self.delegates makeObjectsPerformSelector:@selector(modelDidChange:) withObject:self];
}

- (void) modelDidUpdateObject: (id) object atIndexPath: (NSIndexPath *) indexPath {
    [self.delegates makeObjectsPerformSelector:@selector(model:didUpdateObject:atIndexPath:) withObject:self withObject:object withObject:indexPath];
}

- (void) modelDidInsertObject: (id) object atIndexPath: (NSIndexPath *) indexPath {
    [self.delegates makeObjectsPerformSelector:@selector(model:didInsertObject:atIndexPath:) withObject:self withObject:object withObject:indexPath];
}

- (void) modelDidDeleteObject: (id) object atIndexPath: (NSIndexPath *) indexPath {
    [self.delegates makeObjectsPerformSelector:@selector(model:didDeleteObject:atIndexPath:) withObject:self withObject:object withObject:indexPath];
}

- (void) modelDidBeginUpdates {
    [self.delegates makeObjectsPerformSelector:@selector(modelDidBeginUpdates:) withObject:self];
}

- (void) modelDidEndUpdates {
    [self.delegates makeObjectsPerformSelector:@selector(modelDidEndUpdates:) withObject:self];
}

@end
