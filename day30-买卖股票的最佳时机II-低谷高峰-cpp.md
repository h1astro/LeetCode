
@[TOC](LeetCode-day30-买卖股票的最佳时机II-低谷高峰-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

```
输入: [7,1,5,3,6,4]
输出: 7

```

> 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
>      随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

示例 2:

```
输入: [1,2,3,4,5]
输出: 4
```

> 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
>      注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
>      因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3:

```
输入: [7,6,4,3,1]
输出: 0
```

>  解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。



## 题解

> 参考[题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/)和[](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-tao-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-xiang/)
> 时间复杂度: $O(n)$， 
> 空间复杂度: $O(1)$
> 执行用时：$16 ms$ 

**一次遍历**

*A*+*B*+*C* 的和等于差值D所对应的连续峰和谷的高度之差。

![Profit Graph](https://pic.leetcode-cn.com/6eaf01901108809ca5dfeaef75c9417d6b287c841065525083d1e2aac0ea1de4-file_1555699697692)



## cpp代码

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num=prices.size();
        if(num==0)return 0;
        int profix=0;
        for(int i=1;i<num;i++){
            if(prices[i-1]<prices[i]){
                profix+=prices[i]-prices[i-1];
            }
        }
        return profix;
    }
};
```
