@[TOC](LeetCode-[46. 全排列](https://leetcode-cn.com/problems/permutations/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/3sum-closest/)

给定一个**没有重复**数字的序列，返回其所有可能的全排列。

**示例:**

```
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```



## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode/)
> 时间复杂度是 $O(\sum_{k=1}^{N}P(N,k))​$，  $P(N, k) = \frac{N!}{(N - k)!} = N (N - 1) ... (N - k + 1)​$
> 空间复杂度$O(N!)​$,
> 执行用时：$120 ms​$ 

**回溯递归思想**

回溯法是一种通过探索所有可能的候选解来找出所有的解的算法。

首先如果不考虑如何写代码，数学思维考虑应该如何做，

`1-2-3-4，1-2-4-3，1-3-2-4，1-3-4-2，1-4-3-2，1-4-2-3，`

`2-1-3-4，2-1-4-3，2-3-1-4，2-3-4-1，2-4-3-1，2-4-1-3，`

`...`

以这样的方式进行有序寻找。

1. 如果第一个整数有索引 `n`，意味着当前排列已完成。将当前排序的顺序存入

2. 遍历索引`first`到索引`n - 1`的所有整数。
   1. 在排列中放置第 `i` 个整数， 即 `swap(nums[first], nums[i])`.
   2. 继续生成从第 `i` 个整数开始的所有排列: `backtrack(first + 1)`.
   3. 现在回溯，即通过 `swap(nums[first], nums[i])` 还原.



## python代码实现

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first=0):
            if first==n:				#如果相等
                lists.append(nums[:])
            else:
                for i in range(first,n):
                    nums[first],nums[i]=nums[i],nums[first] 
                    backtrack(first+1)					   #从第 i 个整数开始的所有排列
                    nums[first],nums[i]=nums[i],nums[first]  #回溯
        n=len(nums)
        lists=[]
        backtrack()

        return lists
```