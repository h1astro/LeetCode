@[TOC](LeetCode-day37-重复数字-1sort-2map-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/contains-duplicate/)

给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

```
输入: [1,2,3,1]
输出: true
```

示例 2:

```
输入: [1,2,3,4]
输出: false
```

示例 3:

```
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
```

## 题解

> 参考[题解](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-bnw7cgeofh/)
> sort
> 时间复杂度: $O(nlogn)$， 
> 执行用时：$36 ms$
> map
> 时间复杂度: $O(n)$， ??
> 执行用时：$76 ms$ 

**1.sort**

利用stl里的快排sort，排序后一一遍历，直到连续出现两个及以上相同的数，则重复，返回false

**2.map**

每个没出现的数进插入到map中，直到出现map中该键值对应的值重复，返回true

## cpp sort

```c++
class Solution {
    static bool cmp(const int &a,const int &b)
    {
        return a<b;
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};

```



## cpp map

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> map_a;
        for(int i=0;i<nums.size();i++){
            if(map_a.count(nums[i])){   //如果已经有一个了，说明重复了
                return true;
            }
            else{
                map_a.insert(map<int,int>::value_type(nums[i],1));                
            }
        }
        return false;
    }
};
```
