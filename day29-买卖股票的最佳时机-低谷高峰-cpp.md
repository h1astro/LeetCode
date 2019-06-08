@[TOC](LeetCode-day29-买卖股票的最佳时机-低谷高峰-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。
```
示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```


## 题解

> 参考[题解](https://leetcode-cn.com/problems/merge-sorted-array/solution/zui-jian-dan-de-cha-ru-pai-xu-by-newcoderlife/)]
> 时间复杂度: $O(n)$， 
> 空间复杂度: $O(1)$
> 执行用时：$12 ms$ 

**一次遍历**

找出低谷和低谷后剩下的几天中的高峰值

遍历的同时，更新当前最小值，以及利润最大值

![Profit Graph](https://pic.leetcode-cn.com/cc4ef55d97cfef6f9215285c7573027c4b265c31101dd54e8555a7021c95c927-file_1555699418271)

## cpp代码

```c++
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num=prices.size();
        cout<<"size is :"<<num<<"  "<<endl;
        if(num==0)return 0;
        int min=prices[0];
        int profix=0;
        for(int i=0;i<num;i++){
            min=min<prices[i]?min:prices[i];
            profix=profix>prices[i]-min?profix:prices[i]-min;
        }
        return profix;
    }
};


int main(){
    Solution sol=Solution();
    vector<int> nums1;
    for(int i=-3;i<6;i++){
        nums1.push_back(i*i-2*i+6);
    }
    nums1.push_back(10);
    nums1.push_back(9);
    nums1.push_back(15);
	//21 14 9 6 5 6 9 14 21 10 9 15
    //max:21-5=16
    int num=sol.maxProfit(nums1);
    cout<<"return is :"<<num<<endl;
    return 0;
}
```



