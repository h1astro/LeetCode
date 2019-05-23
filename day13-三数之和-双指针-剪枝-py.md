@[TOC](LeetCode-[15. 三数之和](https://leetcode-cn.com/problems/3sum/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/3sum)

给定一个包含 *n* 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 *a，b，c ，*使得 *a + b + c =* 0 ？找出所有满足条件且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

```
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```



## 题解

> 参考[题解1](https://leetcode-cn.com/problems/3sum/solution/three-sum-ti-jie-by-wonderful611/)以及[题解2](https://leetcode-cn.com/problems/3sum/solution/ti-mu-ming-ming-hen-jian-dan-ke-wo-wei-shi-yao-lao/)
> 时间复杂度是 $O(n^2)$，。
> 空间复杂度$O(n)$,
> 执行用时：892 ms$ 

**双指针的思想以及剪枝**

题解1介绍的很详细，先是举例了两数之和的优化方案，通过建立一个哈希表，时间从$O(n^2)$降到$O(n)$。

此题也是，可以从$O(n^3)$降到$O(n^2)$，但是还需要进行优化，为达到更快的效果就行，先进行排序$O(nlog_{}{(n)})$，然后一次固定一个，然后进行依次遍历，对一些不符合条件的进行剪枝不遍历。如，快排序后，最左边即最小值＞0,则不可能存在三数和=0的情况；最右边即最大值<0,则也不可能存在。

另外再遍历的过程中，需要固定的一个位置$c$的从0到length遍历，然后利用双指针的思想，两个$left$和$right$，然后进行遍历循环查找，此处不是双重循环

1. 如果三数之和sum=0，将三个位置对应的值$[list[c],list[left],list[right]]$ append到list中

   > 还需要考虑到不能存入重复的三个值，while循环，如果$left$和$left+1$对应的值一样就跳过，$right$也一样

2. sum<0，说明左边的能力太弱了，需要找个能力再强一点的，$left=left+1$
3. sum>0，说明右边的能力太强了，需要找个能力再弱一点的，$right=right-1$
4. 此外还需要对一样值的c进行跳过



## python代码实现

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        lists=[]
        len_nums=len(nums)
        nums.sort()    #进行排序  时间o(nlogn)
        # 如果最小的为正  or 最大的为负  说明不存在
        if(len_nums<3 or nums[len_nums-1]<0):
            return []
        c=0
        while c <len_nums-1:
            if nums[c]>0:        #如果最左边的就大于0了 
                break
            l=c+1                #从c右边第一个开始
            r=len_nums-1 
            while l<r:           #遍历循环查找符合条件的
                total=nums[l]+nums[r]+nums[c]
                if total==0:  	#若符合条件
                    lists.append([nums[c],nums[l],nums[r]])
                    while l<r and nums[l]==nums[l+1]:	#防止加入一样的
                        l=l+1
                    while l<r and nums[r]==nums[r-1]:   #防止加入一样的
                        r=r-1
                    l=l+1
                    r=r-1
                elif total<0:						#左边的太小了，换个更大的
                    l=l+1
                else:
                    r=r-1
            while c<len_nums-1 and nums[c]==nums[c+1] :   #过滤一样的值
                c=c+1            
            c=c+1
        return lists
```

## 
