//
//  TKListTableDataSource.h
//  TableKitDemo
//
//  Created by Matthew Purland on 9/12/13.
//
//

#import <Foundation/Foundation.h>
#import "TKTableDataSource.h"

@interface TKListTableDataSource : TKTableDataSource

- (instancetype) initWithItems: (NSArray *) items;
+ (instancetype) dataSourceWithItems: (NSArray *) items;

@end
