//
//  ESMutableDictionary.h
//
//  Created by Doug Russell
//  Copyright (c) 2011 Doug Russell. All rights reserved.
//  
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//  
//  http://www.apache.org/licenses/LICENSE-2.0
//  
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//  

#import <Foundation/Foundation.h>
#import "ARCLogic.h"

/**
 * Drastically simplified, but thread safe mutable dictionary.
 * 
 * (Thread safety is around manipulating membership in collection, 
 * not around manipulating members of the collection on multiple threads)
 */

@interface ESMutableDictionary : NSObject

- (void)setObject:(id)obj forKey:(id<NSCopying>)key;
- (void)removeObjectForKey:(id<NSCopying>)key;
- (id)objectForKey:(id<NSCopying>)key;

#if HASWEAK
- (void)setWeakObject:(id)obj forKey:(id<NSCopying>)key;
- (void)removeWeakObjectForKey:(id<NSCopying>)key;
- (__weak id)weakObjectForKey:(id<NSCopying>)key;
#endif

- (NSUInteger)count;
// Returns only non weak objects
- (NSDictionary *)copyDictionary;

@end
