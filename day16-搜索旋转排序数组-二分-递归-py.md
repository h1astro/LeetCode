@[TOC](LeetCode-[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 *O*(log *n*) 级别。

**示例 1:**

```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```

**示例 2:**

```
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```



## 题解

> 参考[题解1](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/)和[题解2](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/comments/89093)
> 时间复杂度是 $O(log(n))$， 
> 空间复杂度$O(1)$,
> 执行用时：$40 ms$ 

**二分思想**

> 查找的target不是反转的某个点，以及处理好边界值，输入为空或单个值

反转的节点的前后两部分是各自有序的，mid位置索引的值和target会有几种情况

举例：

`4 5 6 7 8 0 1 2 3 `

1. mid 若在4-8之间的一个索引，对于target的值有三种情况

   | 向前半部分寻找             | 向后半部分寻找             |
   | -------------------------- | -------------------------- |
   | $nums[i]<target<nums[mid]$ | $nums[i]<nums[mid]<target$ |
   |                            | $target<nums[i]$           |

2. mid 若在0-3之间的一个索引，对于target的值有三种情况

   | 向前半部分寻找             | 向后半部分寻找             |
   | -------------------------- | -------------------------- |
   | $nums[mid]<nums[i]>target$ | $nums[mid]<target<nums[i]$ |
   | $target<nums[mid]<nums[i]$ |                            |

   

## python代码实现

```python
class Solution:
    def search(self, nums, target) :
        def half_search(nums,target,i,j):
            mid=int(0.5*(i+j))
            if nums[mid]==target:   #如果等于以下三个边界值
                return mid
            elif nums[i]==target:
                return i
            elif nums[j]==target:
                return j
            elif j-i==1 or j==i:    #处理两个都不是的 或 只有一个值 的情况
                return -1
            if (nums[i]<target and target<nums[mid]) or (nums[mid]<nums[i] and nums[i]<target) or (target<nums[mid] and nums[mid]<nums[i]):
                return half_search(nums,target,i,mid)
            elif (nums[i]<nums[mid] and nums[mid]<target) or target<nums[i]:
            # or another way ==    else:
                return half_search(nums,target,mid,j)
        i=0
        j=len(nums)-1
        if not nums:   #处理输入为空的情况
            return -1
        return half_search(nums,target,i,j)
```
