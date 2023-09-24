//
//  RNBODelegate.hpp
//  SwiftRNBO_Example_multiplatfrom_SwiftUI
//
//  Created by Jaehyeon Park on 2023/09/24.
//

#ifndef RNBODelegate_hpp
#define RNBODelegate_hpp

@protocol RNBODelegate

- (void)didReceiveParameter:(size_t)index :(double)value;
- (void)didReceiveMessage:(NSString* _Nonnull)tag :(int)type :(NSArray* _Nonnull)values;

@end

#endif /* RNBODelegate_hpp */
