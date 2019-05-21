@[TOC](LeetCode-[53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/maximum-subarray/)

给定一个整数数组 `nums` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**示例:**

```
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```



## 题解

> 参考[题解](https://leetcode-cn.com/problems/maximum-subarray/solution/4msdp-de-go-shi-xian-by-elliotxx/)
> 时间复杂度是 $O(n)$，
> 空间复杂度$O(1 )$,
> 执行用时：$52 ms$

**DP思想**

依次遍历整个数组

如果当前总和小于0，则放弃，重新赋值为下一个值，

最后比较当前总和和最大总和



## python代码实现

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        final_max=nums[0]
        current_max=0
        for num in nums:        
            if current_max<0:
                current_max=num
            else:
                current_max=current_max+num
            if current_max>final_max:
                final_max=current_max
        return final_max
```

