@[TOC](LeetCode-合并两个有序数组-双指针-简单-cpp)
## 题目回顾

[传送门](https://leetcode-cn.com/problems/merge-sorted-array/)

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

`输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3`

`输出: [1,2,2,3,5,6]`



## 题解

> 参考[题解](https://leetcode-cn.com/problems/merge-sorted-array/solution/zui-jian-dan-de-cha-ru-pai-xu-by-newcoderlife/)]
> 时间复杂度: $O(n)$， 
> 空间复杂度: $O(N)$
> 执行用时：$10 ms$ 

**双指针，以及cpp vector函数操作**

新建一个vector，将nums1和nums2的依次比较大小，使用双指针，比较大小插入到新vector里，最后使用vector的swap交换成新vector里的数

## cpp代码

```c++
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        if(m==0){
            nums1.swap(nums2);
            return;
        }
        if(n==0){
            return;
        }
        vector<int>num;
        num.reserve(m);
        int i=0;
        int j=0;
        while(i<m&&j<n){	//比较大小，有序插入到新vector中
            if(nums1[i]<nums2[j]){
                num.push_back(nums1[i]);
                i++;
            }
            else{
                num.push_back(nums2[j]);
                j++;
            }         
        }
        while(j<n){
            num.push_back(nums2[j]);
            j++;
        }
        while(i<m){
            num.push_back(nums1[i]);
            i++;
        }
        nums1.swap(num);	//nums1的全部置换为num中的数
    }
};

int main(){

    Solution sol=Solution();
    vector<int> nums1;
    for(int i=0;i<4;i++){
        nums1.push_back(i);
    }
    vector<int> nums2;
    for(int i=1;i<5;i++){
        nums2.push_back(i*i);
    }
    
    sol.merge(nums1,4,nums2,4);
    for(int i=0;i<8;i++){
        cout<<nums1[i]<<" "<<endl;
    }
    return 0;
}
```



