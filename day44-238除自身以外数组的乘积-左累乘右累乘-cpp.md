
@[TOC](LeetCode-day44-238除自身以外数组的乘积-左累乘右累乘-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/product-of-array-except-self/)

给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

```
输入: [1,2,3,4]
输出: [24,12,8,6]
```

> 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

## 题解

> 参考[题解](https://leetcode-cn.com/problems/product-of-array-except-self/solution/cheng-ji-dang-qian-shu-zuo-bian-de-cheng-ji-dang-q/)
> 时间复杂度: $O(N)$， 
> 空间复杂度$O(N)$，
> 执行用时：$56 ms$

**乘积 = 当前数左边的乘积 * 当前数右边的乘积**

开辟一个n的新数组res，

一个循环，累积相乘,得到每个res[i]，类似n!，

第二次循环从尾部开始累积相乘，并乘以对应位置的新数组res[i]

$$res[i]=\prod_{0}^{i-1}{res[j]}*\prod_{n}^{i+1}{res[j]}$$

> 公式可能有误

## cpp

```c++
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<=1){
            return nums;
        }
        vector<int> vec;
        int k=1;
        //左乘累积
        for(int i=0;i<nums.size();i++){
            vec.push_back(k);
            k*=nums[i];
        }
        k=1;
        //右乘累积并乘以上一轮左乘后的结果
        for(int i=nums.size()-1;i>=0;i--){
            vec[i]*=k;
            k*=nums[i];
        }
        return vec;        
    }
};


int main(){

    Solution sol=Solution();
    vector<int> vec={1,2,3,4};

    // expect result is  [24 12 8 6]
    vector<int> vec2=sol.productExceptSelf(vec);
    for(int i=0;i<vec2.size();i++){
        cout<<vec2[i]<<" ";        
    }
    
    return 0;
}
```
