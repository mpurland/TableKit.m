//
//  TKFilter.h
//  TableKitDemo
//
//  Created by Matthew Purland  on 8/20/13.
//
//

#import <Foundation/Foundation.h>

@protocol TKFilter;

/**
 Filter delegate for notifying a listener of a filter of completion.
 */
@protocol TKFilterDelegate <NSObject>

/**
 Notifies the delegate that the filter did complete using the given constraint and produced the given results.
 */
- (id) filter: (id<TKFilter>) filter didFilterCompleteWithConstraint: (id) constraint results: (id) results;

@end

@protocol TKFilter <NSObject>
@required

/**
 Delegate for the filter.
 */
@property (nonatomic, weak) id<TKFilterDelegate> delegate;

/**
 Filter using the given constraint.
 */
- (void) filter: (id) constraint;

@end

@interface TKFilter : NSObject<TKFilter>

@property (nonatomic, weak) id<TKFilterDelegate> delegate;

@end
