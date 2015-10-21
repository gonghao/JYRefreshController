//
//  JYPullToLoadMoreController.h
//  JYRefreshController
//
//  Created by Alvin on 14/11/17.
//
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, JYLoadMoreState)
{
  JYLoadMoreStateStop = 0,
  JYLoadMoreStateTrigger = 1,
  JYLoadMoreStateLoading = 2,
};

@protocol JYRefreshView;

@interface JYPullToLoadMoreController : NSObject

@property (nonatomic, readonly, strong) UIScrollView *scrollView;

@property (nonatomic, assign) BOOL enable;

- (void)setEnable:(BOOL)enable withAnimation:(BOOL)animated;

/**
 *  Set to NO, if need user dragging to trigger load more action. Default is YES.
 */
@property (nonatomic, assign) BOOL autoLoadMore;

/**
 *  设置为 YES 表示把 `customView` 放在 `scrollView` 内容部分的下方；否则表示把
 *  `customView` 放在 `scrollView.contentInset.bottom` 的下方。
 */
@property (nonatomic, assign) BOOL showRefreshControllerBelowContent;

@property (nonatomic, readonly, assign) JYLoadMoreState loadMoreState;

@property (nonatomic, copy) void(^pullToLoadMoreHandleAction)();

- (instancetype)initWithScrollView:(UIScrollView *)scrollView;

- (void)triggerLoadMoreWithAnimated:(BOOL)animated;

- (void)stopLoadMoreCompletion:(void(^)())completion;

- (void)setCustomView:(UIView <JYRefreshView> *)customView;

@end
