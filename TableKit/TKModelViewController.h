//
// Created by Matthew Purland on 9/12/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>
#import "TKModel.h"

/**
 Abstract controller for handling a model.
 */
@interface TKModelViewController : NSObject

/**
 The model.
 */
@property(nonatomic, weak) id <TKModel> model;

/**
 Reloads the model data.
 */
- (void) reloadData;

/**
 Reloads the model data (if needed).
 */
- (void) reloadDataIfNeeded;

@end