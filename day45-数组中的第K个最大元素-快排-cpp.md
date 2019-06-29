
@[TOC](LeetCode-day45-数组中的第K个最大元素-快排-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

```

示例 2:

```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

说明:

- 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

## 题解

> 参考[题解](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-gpe3dbjds/) 和 [思路](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/ji-chong-si-lu-by-dox1994/)
> 时间复杂度: 快排 $O(nlog(n))$， 
> 空间复杂度$O(N)$，
> 执行用时：$28 ms$

**简单粗暴的排序法**
先排序，然后直接取第k位置就可以

**冒泡**
类似于冒泡排序的思路，从小往大冒泡，冒k次之后就得到第k大的数了

**小根堆**
维护一个小根堆，遍历数组，如果当前元素大于根，则加入堆中；如果加入后堆的元素数量多于k，则弹出根元素。 遍历一遍之后，根就是第k大的元素。

**类似快排的划分思路**
先任取一个数，把比它大的数移动到它的左边，比它小的数移动到它的右边。移动完成一轮后，看该数的下标（从0计数），如果刚好为k-1则它就是第k大的数，如果小于k-1，说明第k大的数在它右边，如果大于k-1则说明第k大的数在它左边，取左边或者右边继续进行移动，直到找到。



此处只用了快排

## cpp

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        static bool ismax(const int &a,const int &b){
            return a>b;
        }
        int findKthLargest(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end(),ismax);
            return nums[k-1];
        }
};

int main(){
    Solution sol=Solution();
    vector<int> vec={1,2,3,4,165,24};
    //result repect is : 24
    cout<<sol.findKthLargest(vec,2);
        
    return 0;
}
```
