//
// Created by Matthew Purland on 9/12/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>
#import "TKDataSource.h"

/**
 Controller for handling a data source.
 */
@interface TKTableViewController : UITableViewController

/**
 Data source for the table view.
 */
@property (nonatomic, weak) id<TKDataSource> dataSource;

@end