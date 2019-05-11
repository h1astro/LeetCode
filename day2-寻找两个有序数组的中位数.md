@[TOC](LeetCode-寻找两个有序数组的中位数)
## 题目回顾
[传送门](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
```
nums1 = [1, 3]
nums2 = [2]
```
则中位数是 2.0
示例 2:
```
nums1 = [1, 2]
nums2 = [3, 4]
```
则中位数是 (2 + 3)/2 = 2.5

## 题解
>待后续改进实现 [\[二分题解\]](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/shuang-zhi-zhen-by-powcai/)
没有满足题目要求的时间复杂度$O(log(m+n))$
现在的时间复杂度是$O{(m+n)}$
执行用时：$56 ms$

两个$vector1,vector2$依次读取第一个值，比较哪个值比较小，若$vector2$的当前第一个值小，就将该值存储到新建第三个$vector3$里，并自身的$vector2$删除该值。这样遍历$(m+n)/2+1$次，最后返回合并后$vector3$的下标中间位置的值。
* 需要注意的一个地方是，会出现还没遍历完其中一个$vector$都已经删完了，需要给该值赋一个足够大的值

## cpp 代码实现
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nodes;
        int len1=nums1.size();
        int len2=nums2.size();
        int num1;
        int num2;
        int num;
        vector<int>::iterator k1 = nums1.begin();
        vector<int>::iterator k2 = nums2.begin();
        for(int i=0;i<(len1+len2)/2+1;i++){
            if(nums1.size()==0){     //防止当前nums1已经遍历完
                num1=10000000;
            }
            else{
                num1=nums1.front();  //获得当前nums1第一个值
            }
            if(nums2.size()==0){
                num2=10000000;
            }
            else{
                num2=nums2.front();
            }
            if(num1<num2){
                k1 = nums1.begin();   //迭代获取当前第一个值
                nums1.erase(k1);      //删除nums1的值
                nodes.push_back(num1);//添加到第三个新建的vector里
            }
            else{
                k2 = nums2.begin();
                nums2.erase(k2);
                nodes.push_back(num2);
            }
        }
        if((len1+len2)%2==1){
            return nodes[(len1+len2-1)/2];
        }
        else{
            num=nodes[(len1+len2)/2]+nodes[(len1+len2)/2-1];
            return (double)num/2;
        }
    }
};
```
