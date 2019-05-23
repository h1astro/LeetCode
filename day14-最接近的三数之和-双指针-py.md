@[TOC](LeetCode-[16. 最接近的三数之和](https://leetcode-cn.com/problems/3sum-closest/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/3sum-closest/)

此题，跟[三数之和](https://leetcode-cn.com/problems/3sum/)类似。

给定一个包括 *n* 个整数的数组 `nums` 和 一个目标值 `target`。找出 `nums` 中的三个整数，使得它们的和与 `target` 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

```
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
```



## 题解

> 参考[题解](https://leetcode-cn.com/problems/3sum/solution/three-sum-ti-jie-by-wonderful611/)
> 时间复杂度是 $O(n^2)$，。
> 空间复杂度$O(n)$,
> 执行用时：$116 ms$ 

**双指针的思想**

题解介绍的很详细，先是举例了两数之和的优化方案，通过建立一个哈希表，时间从$O(n^2)$降到$O(n)$。

此题也是，可以从$O(n^3)$降到$O(n^2)$，但是还需要进行优化，为达到更快的效果就行，先进行排序$O(nlog_{}{(n)})$，然后一次固定一个，然后进行依次遍历，对一些不符合条件的进行剪枝不遍历。

另外再遍历的过程中，需要固定的一个位置$c$的从0到length遍历，然后利用双指针的思想，两个$left$和$right$，然后进行遍历循环查找，此处不是双重循环。

> 不同于三数之和需要进行很多的剪枝。

多了一个存储比较最小之差$mindiff$，以及最接近target的三数之和$sums$

1. total=nums[l]+nums[r]+nums[c]-target
2. 如果三数之和sum=target，则直接返回target
3. 比较diff=abs(total-target)
   1. mindiff>diff, 则mindiff=diff，sums=total，更新最小差值以及最接近target的三数之和
4. sum<0，说明左边的能力太弱了，需要找个能力再强一点的，$left=left+1$
5. sum>0，说明右边的能力太强了，需要找个能力再弱一点的，$right=right-1$
6. 此外还需要对一样值的c进行剪枝跳过，可以降低一些运行时间



## python代码实现

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        len_nums=len(nums)
        min_diff=100000
        sums=0
        nums.sort()    #进行排序  时间o(nlogn)
        c=0
        while c <len_nums-1:
            l=c+1                #从c右边第一个开始
            r=len_nums-1 
            while l<r:           #遍历循环查找符合条件的
                total=nums[l]+nums[r]+nums[c]
                diff=total-target
                if diff==0:  	#若符合条件
                    return target
                    # lists.append([nums[c],nums[l],nums[r]])
                    # while l<r and nums[l]==nums[l+1]:	#防止加入一样的
                    #     l=l+1
                    # while l<r and nums[r]==nums[r-1]:   #防止加入一样的
                    #     r=r-1
                    # l=l+1
                    # r=r-1
                elif min_diff>abs(diff):		#左边的太小了，换个更大的
                    min_diff=abs(diff)
                    sums=total
                elif diff<0:
                    l=l+1
                elif diff>0:
                    r=r-1
            while c<len_nums-1 and nums[c]==nums[c+1] :   #剪枝，过滤一样的值
                c=c+1            
            c=c+1
        return sums
```

