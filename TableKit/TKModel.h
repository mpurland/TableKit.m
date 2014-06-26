//
//  TKModel.h
//  TableKitDemo
//
//  Created by Matthew Purland  on 8/20/13.
//
//

#import <Foundation/Foundation.h>

@protocol TKModel;

typedef NS_ENUM(NSInteger, TKModelLoadType) {
    TKModelLoadTypeAll = 0,
    TKModelLoadTypeMore = 1
};

/**
 Protocol for a TKModel delegate.
 */
@protocol TKModelDelegate <NSObject>

/**
 Model did successfully start loading.
 */
- (void)modelDidStartLoad: (id<TKModel>) model;

/**
 Model did successfully finish loading.
 */
- (void)modelDidFinishLoad:(id<TKModel>)model;

/**
 Model did fail loading with the given error.
 */
- (void)model:(id<TKModel>)model didFailLoadWithError:(NSError*)error;

/**
 Model did cancel loading.
 */
- (void)modelDidCancelLoad:(id<TKModel>)model;

/**
 Model did invalidate with erase.
 */
- (void)model:(id<TKModel>)model didInvalidateWithErase: (BOOL) erase;

/**
 Model did change.  It should be assume that the entire model may have changed.
 */
- (void)modelDidChange:(id<TKModel>)model;

/**
 Model did update a given object for the given index path.
 */
- (void)model:(id<TKModel>)model didUpdateObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 Model did insert a given object for the given index path.
 */
- (void)model:(id<TKModel>)model didInsertObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 Model did delete a given object for the given index path.
 */
- (void)model:(id<TKModel>)model didDeleteObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 Model did begin a multi-stage update.  This will occur before didUpdate, didInsert or didDelete.
 */
- (void)modelDidBeginUpdates:(id<TKModel>)model;

/**
 Model did complete a multi-stage update.  This will occur after didUpdate, didInsert or didDelete.
 */
- (void)modelDidEndUpdates:(id<TKModel>)model;

@end

/**
 Protocol for a model.
 */
@protocol TKModel <NSObject>
@required

/**
 Delegates the model delegates all model events to.
 */
@property (nonatomic, strong) NSArray *delegates; // Delegates must conform to TKModelDelegate protocol

/**
 Load the model using the given model load type.
 */
- (void) load:(TKModelLoadType)loadType;

/**
 Load the model.
 */
- (void) load;

/**
 Load more data on the model.
 */
- (void) loadMore;

/**
 Cancels a load when in progress.
 */
- (void) cancel;

/**
 Invalidate the model causing a reload.  Optionally erase the model data if given.
 */
- (void) invalidate: (BOOL) erase;

/**
 If the model is loaded.
 */
- (BOOL) isLoaded;

/**
 If the model is loading.
 */
- (BOOL) isLoading;

/**
 If the model is loading more.
 */
- (BOOL) isLoadingMore;

/**
 If the model is outdated.
 */
- (BOOL) isOutdated;

@end

/**
 Default implementation for TKModel.
 */
@interface TKModel : NSObject <TKModel>

/**
 Notify model delegates of model events.
 */
- (void) modelDidStartLoad;
- (void) modelDidFinishLoad;
- (void) modelDidFailLoadWithError: (NSError *) error;
- (void) modelDidCancelLoad;
- (void) modelDidInvalidateWithErase: (BOOL) erase;
- (void) modelDidChange;
- (void) modelDidUpdateObject: (id) object atIndexPath: (NSIndexPath *) indexPath;
- (void) modelDidInsertObject: (id) object atIndexPath: (NSIndexPath *) indexPath;
- (void) modelDidDeleteObject: (id) object atIndexPath: (NSIndexPath *) indexPath;
- (void) modelDidBeginUpdates;
- (void) modelDidEndUpdates;

@end
