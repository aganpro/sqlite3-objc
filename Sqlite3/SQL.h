//
//  SLSQL.h
//  Sqlite3
//
//  Created by youknowone on 10. 11. 1..
//  Copyright 2010 youknowone.org All rights reserved.
//
/*
 ** 2001 September 15
 **
 ** The author disclaims copyright to original source code.  In place of
 ** a legal notice, here is a blessing:
 **
 **    May you do good and not evil.
 **    May you find forgiveness for yourself and forgive others.
 **    May you share freely, never taking more than you give.
 **
 */

#import <Foundation/Foundation.h>

@interface SLSQL : NSObject {
    NSMutableString *_SQL; 
}

@property(readonly) NSString *SQL;

- (SLSQL *)groupBy:(NSString *)groups;
- (SLSQL *)groupBy:(NSString *)groups having:(NSString*)groupContidion;
- (SLSQL *)orderBy:(NSString *)condition;
- (SLSQL *)limit:(NSUInteger)count;
- (SLSQL *)limit:(NSUInteger)from count:(NSUInteger)count;

@end

@interface SLSQL (SLSQLCreation)

- (id)initWithString:(NSString *)string;
+ (id)initWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
+ (SLSQL *)SQLWithString:(NSString *)string;
+ (SLSQL *)SQLWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);

+ (SLSQL *)SQLWithSelect:(NSString *)column from:(NSString *)table where:(NSString *)condition;
+ (SLSQL *)SQLWithDeleteFrom:(NSString *)table where:(NSString*)condition;
+ (SLSQL *)SQLWithInsertInto:(NSString *)table values:(NSString*)values;
+ (SLSQL *)SQLWithInsertInto:(NSString *)table columns:(NSString*)columns values:(NSString*)values;
+ (SLSQL *)SQLWithUpdate:(NSString *)table set:(NSString*)setStatements where:(NSString*)condition;

@end


@interface SLSQL (SLSQLStringGenerators)

+ (NSString *)alias:(NSString *)SQL as:(NSString *)alias;
+ (NSString *)customListSeparatedBy:(NSString *)separator withStrings:(NSString *)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSString *)commaListWithStrings:(NSString *)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSString *)rawCommaListWithStrings:(NSString *)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSString *)andConditionWithStrings:(NSString *)firstSQL, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSString *)orConditionWithStrings:(NSString *)firstSQL, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSString *)customListSeparatedBy:(NSString *)separator withArray:(NSArray *)array;
+ (NSString *)commaListWithArray:(NSArray *)array;
+ (NSString *)rawCommaListWithArray:(NSArray *)array;
+ (NSString *)andConditionWithArray:(NSArray *)array;
+ (NSString *)orConditionWithArray:(NSArray *)array;

@end

