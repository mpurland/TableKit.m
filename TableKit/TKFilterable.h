//
//  TKFilterable.h
//  TableKitDemo
//
//  Created by Matthew Purland  on 8/20/13.
//
//

#import <Foundation/Foundation.h>

#import "TKFilter.h"

/**
 Protocol for defining filterable behavior (usually with a data source).
 */
@protocol TKFilterable <NSObject>

/**
 Returns the filter for the filterable data.
 */
- (id<TKFilter>) filter;

/**
 Apply the filter.
 */
- (void) applyFilter: (id<TKFilter>) filter;

@end

@interface TKFilterable : NSObject<TKFilterable>

@property (nonatomic, strong, readonly) id<TKFilter> filter;

@end
