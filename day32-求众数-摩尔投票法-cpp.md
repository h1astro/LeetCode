
@[TOC](LeetCode-day32-求众数-摩尔投票法-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/majority-element/)

给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2



## 题解

> 参考[题解](https://leetcode-cn.com/problems/majority-element/solution/qiu-zhong-shu-by-gpe3dbjds1/)和[题解2](https://leetcode-cn.com/problems/majority-element/solution/qiu-zhong-shu-by-gpe3dbjds1/)
> 时间复杂度: $O(n)$， 
> 空间复杂度: $O(1)$
> 执行用时：$20 ms$ 

**摩尔投票法**

计数count，如果为0的话，就找下一个数，如果遇到相同的计数加1，否则-1。

考虑到题意的众数的数量是超过n/2的，所以这种方法可取

方法二，进行排序，然后返回n/2位置的数，也即为众数



## cpp代码

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nums_size=nums.size();
        int num=0;
        int count=0;
        for(int i=0;i<nums_size;i++){
            if(count==0){
                num=nums[i];
                count=1;
            }
            else if(num==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return num;
    }
    // 方法二
	// static bool cmp(const int &a, const int &b)
	// {
	// 	return a < b;
	// }
	// int majorityElement(vector<int>& nums) {
	// 	sort(nums.begin(), nums.end(), cmp);
	// 	return nums[nums.size()/2];
	// }
};
```
