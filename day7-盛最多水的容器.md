@[TOC](LeetCode-盛最多水的容器)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/container-with-most-water/)

给定 *n* 个非负整数 *a*1，*a*2，...，*a*n，每个数代表坐标中的一个点 (*i*, *ai*) 。在坐标内画 *n* 条垂直线，垂直线 *i* 的两个端点分别为 (*i*, *ai*) 和 (*i*, 0)。找出其中的两条线，使得它们与 *x* 轴共同构成的容器可以容纳最多的水。

**说明：** 你不能倾斜容器，且 *n* 的值至少为 2。

![img](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

**示例:**

```
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
```



## 题解

参考[官方题解](https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode/ )
时间复杂度是 $O(n)$
空间复杂度$O(1)$
执行用时：$68  ms$

一开始想到的就是最普遍的暴力法，两次for循环遍历，找最大的，时间复杂度$O(\frac{(n*(n-1))}{2})$。

然后就**超时**了。



```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max=0
        for i in range(len(height)):
            for j in range(i+1,len(height)):
                current=min(height[i],height[j])
                area=(j-i)*current
                if max<area:
                    max=area
        return max
```



所以需要换更好的算法------**双指针法**。

这种方法背后的思路在于，两线段之间形成的区域总是会受到其中较短那条长度的限制。此外，两线段距离越远，得到的面积就越大。

我们在由线段长度构成的数组中使用两个指针，一个放在开始，一个置于末尾。 此外，我们会使用变量 $maxarea$来持续存储到目前为止所获得的最大面积。 在每一步中，我们会找出指针所指向的两条线段形成的区域，更新$ maxarea$，并将指向**较短线段**的指针向较长线段那端**移动一步**。

## python 代码实现

```python
class Solution:
    def maxArea(self, height):
        max=0
        left=0
        right=len(height)-1
        for i in range(len(height)):
            if(height[left]<height[right]):   #左移
                area=(right-left)*height[left]
                left=left+1
            else:							#右移
                area=(right-left)*height[right]
                right=right-1
            if max<area:
                max=area
        return max
```
