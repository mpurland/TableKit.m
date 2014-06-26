//
//  TKDataSource.h
//  TableKitDemo
//
//  Created by Matthew Purland  on 8/20/13.
//
//

#import <Foundation/Foundation.h>

#import "TKModel.h"

/**
 Protocol for a data source.
 */
@protocol TKDataSource <NSObject>
@required

/**
 Model that the data source responds to.
 */
@property (nonatomic, readonly) id<TKModel> model;

/**
 View for data source when model is loading.
 */
- (UIView *) viewForLoading;

/**
 View for data source when model is empty.
 */
- (UIView *) viewForEmpty;

/**
 View for data source when model encountered an error while loading.
 */
- (UIView *) viewForError: (NSError *) error;

@end

/**
 Default implementation for a data source.
 */
@interface TKDataSource : NSObject <TKDataSource>

- (instancetype) initWithModel: (id<TKModel>) model;

@property (nonatomic, strong, getter=viewForLoading) UIView *viewForLoading;
@property (nonatomic, strong, getter=viewForEmpty) UIView *viewForEmpty;
@property (nonatomic, strong, getter=viewForError) UIView *viewForError;

@end
