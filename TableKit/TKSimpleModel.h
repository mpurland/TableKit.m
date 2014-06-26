//
//  TKSimpleModel.h
//  TableKitDemo
//
//  Created by Matthew Purland on 9/12/13.
//
//

#import <Foundation/Foundation.h>
#import "TKModel.h"

@interface TKSimpleModel : TKModel

@property (nonatomic, strong) NSArray *items;

- (instancetype) initWithItems: (NSArray *) items;

@end
