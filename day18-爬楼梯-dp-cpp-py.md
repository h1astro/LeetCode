@[TOC](LeetCode-[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/climbing-stairs/)

假设你正在爬楼梯。需要 *n* 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**注意：**给定 *n* 是一个正整数。

**示例 1：**

```
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```

**示例 2：**

```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```



## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/)，放弃$O(2^n)$超时的暴力法，采用动态规划
> 时间复杂度是 $O(n)$， 
> 空间复杂度$O(n)$,
> 执行用时：$60 ms$ 

**暴力法**

我们将会把所有可能爬的阶数进行组合，也就是 1 和 2 。每一步,继续调用 递归函数模拟爬 1 阶和 2 阶的情形，并返回两个函数的返回值之和。

![Climbing_Stairs](https://pic.leetcode-cn.com/07a21d45a33309d39925127eb0a8611fce5212cb932e4a6fe9914b30c885d1f6-file_1555697913334)

**动态规划**

深入理解，可以发现这个爬楼梯，其实就是一个斐波拉契数列。

这个问题可以被分解为一些包含最优子结构的子问题，即它的最优解可以从其子问题的最优解来有效地构建，我们可以使用动态规划来解决这一问题。

第 $i$ 阶可以由以下两种方法得到：

1. 在第 `(i-1)`阶后向上爬 `1`阶。
2. 在第 `(i-2)`阶后向上爬 `2`阶。

所以到达第 `i` 阶的方法总数就是到第 `(i-1)`阶和第 `(i-2)` 阶的方法数之和。

令 $dp[i]$ 表示能到达第 `i`阶的方法总数：

$$dp[i]=dp[i-1]+dp[i-2]$$

## cpp代码实现

```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;            
        }
        int *count=(int *)malloc(sizeof(int)*(n+1));    
        for(int i=0;i<n+1;i++){
            count[i]=0;
        }
        count[0]=0;
        count[1]=1;
        count[2]=2;
        for(int i=3;i<=n;i++){
            count[i]=count[i-1]+count[i-2];
        }

        return count[n];
    }
};
```



## python代码实现

```python
class Solution:
    def  climbStairs(self, n):
        # def climb_dg(i,n):
        #     if i>n:
        #         return 0
        #     elif i==n:
        #         return 1
        #     return climb_dg(0,n-1)+climb_dg(0,n-2)        
        # count=climb_dg(0,n)
        # return count

        if n == 1:
            return 1    
        dp = [0 for i in range(n+1)]
        dp[1] = 1;
        dp[2] = 2;
        for i in range(3,n+1):
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n]

```
