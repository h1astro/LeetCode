@[TOC](LeetCode-[78. 子集](https://leetcode-cn.com/problems/subsets/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/subsets/)

给定一组**不含重复元素**的整数数组 *nums*，返回该数组所有可能的子集（幂集）。

**说明：**解集不能包含重复的子集。

**示例:**

```
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```



## 题解

> 参考[题解](https://leetcode-cn.com/problems/subsets/solution/wei-yun-suan-by-yi-qu-xin-ci/)
> 时间复杂度是 $O(2^n*n)$， 
> 空间复杂度$O(2^n)$,
> 执行用时：$48 ms$ 

**位运算**

总个数为$2^n$，排列顺序可以想到2进制位运算，

如输入 `[1,2,3]`，输出排列方式有8种，依次将1往左移位和原数进行与运算 $1<<j \quad \&\quad i$

`[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]`

可以对应到如下的8中标记

`0 0 0` ,`0 0 1` ,`0 1 0` ,`0 1 1`

`1 0 0` ,`1 0 1` ,`1 1 0` ,`1 1 1`



## py未优化时间代码

```python
  class Solution:
    def subsets(self, nums) :      
    ## 时间较长   
    	len_nums=len(nums)
        total=2**len_nums
        res=[]
        for i in range(total+1):
            flag_list=[0 for i in range(len_nums)]  #用falg_list标记对应的每个是否存在
            for j in range(len_nums):
                bit=1<<j			
                if bit & i:			#判断该为是否为1
                    flag_list[j]=1                        
            lists=[nums[j] for j in range(len_nums) if flag_list[j]==1]   
            res.append(lists)   
        return res
if __name__=="__main__":
    sol=Solution()
    m=[1,2,3]
    n=3
    num=sol.subsets(m)
    print(num)
```



## py 优化后代码

```python
class Solution:
    def subsets(self, nums) :
    #去掉了可不要的操作 ，优化了时间
        len_nums=len(nums)
        total=2**len_nums
        res=[]
        for i in range(total):
            lists=[nums[j] for j in range(len_nums) if 1<<j & i]   
            res.append(lists)   
        return res
```



## 

