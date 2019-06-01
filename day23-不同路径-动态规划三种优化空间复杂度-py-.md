@[TOC](LeetCode-[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/unique-paths/)

一个机器人位于一个 *m x n* 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

| start | 0    | 0    | 0    | 0    | 0    | 0      |
| ----- | ---- | ---- | ---- | ---- | ---- | ------ |
| 0     | 0    | 0    | 0    | 0    | 0    | 0      |
| 0     | 0    | 0    | 0    | 0    | 0    | finish |

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

例如，上图是一个7 x 3 的网格。有多少可能的路径？

**说明：***m* 和 *n* 的值均不超过 100。

**示例 1:**

```
输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
```

**示例 2:**

```
输入: m = 7, n = 3
输出: 28
```



## 题解

> 参考[题解](https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/)
> 时间复杂度是 $O(n*m)$， 
> 空间复杂度$O(n*m)->O(2n)->O(n)$,
> 执行用时：$80 ms$ 

**动态规划**

核心思想，每个空格的路径由它上方一格和左边一格之和。

首行和首列都为1，因为路径条数只能是一条，要么一直右，要么一直下

$$dp[i][j]=dp[i-1]dp[j]+dp[i][j-1]$$

以下三种优化空间复杂度，核心思想不变



## py 空间复杂度O(n*m)

```python
  class Solution:
    def uniquePaths(self, m, n) :
    	matrix=[]
        for i in range(n):		#初始化矩阵
            matrix.append([1 for j in range(m)])

        for i in range(1,n):
            for j in range(1,m):
                matrix[i][j]=matrix[i-1][j]+matrix[i][j-1]
        print(matrix)
        return matrix[n-1][m-1]
             
if __name__=='__main__':
    sol=Solution()
    m=7
    n=3
    num=sol.uniquePaths(m,n)
    print(num)
```

## py空间复杂度O(2n)

```python
  class Solution:
    def uniquePaths(self, m, n) :
        pre = [1] * n    #前一列
        cur = [1] * n	 #当前列
        for i in range(1, m):
            for j in range(1, n):
                cur[j] = pre[j] + cur[j-1]  #pre[j]=左边一格的路径数  cur[j=1]=上边一格的路径数
            pre = cur[:]				  #更新列
        return pre[-1]
```



## py 空间复杂度O(n)

```python
class Solution:
    def uniquePaths(self, m, n) :
        cur = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                cur[j] += cur[j-1]		#保持最新的一列，cur[j]左边一个路径数  cur[j=1]上边一格路径数
                print(cur[j])
        return cur[-1]
```

