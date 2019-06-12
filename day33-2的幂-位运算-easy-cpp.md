@[TOC](LeetCode-day33-2的幂-位运算-easy-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/power-of-two/)

给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:
```
输入: 1
输出: true
解释: 20 = 1
```
示例 2:
```
输入: 16
输出: true
解释: 24 = 16
```
示例 3:
```
输入: 218
输出: false
```


## 题解

> 参考[题解](https://leetcode-cn.com/problems/power-of-two/solution/2de-mi-ci-fang-de-xing-zhi-by-zui-hou-de-dai-ma/)
> 时间复杂度: $O(log_{2}{n})->O(1)??$， 
> 空间复杂度: $O(1)$
> 执行用时：$4 ms$ 

一开始想到的可能是进行2的整除，并求余数，余数为1，整数不为0，说明不为2的幂。

更好的方法，代码2

位运算，考虑到如果是2的幂的话，二进制只有一位为1，

n-1，原先n的那个位置为1的地方变0，后面几位都为1

`00010000` `n`

`00001111` `n-1` 

`00000000` `n&n-1`

于是得出该判断条件 n>0&&(n&n-1)==0

## cpp代码1

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1)return false;
        int Integer=0;
        int remain=0;
        while(n!=0){
            remain=n%2;
            n=(int)n/2;
            if(remain==1&&n!=0)return false;
        }
        return true;
    }
};
```

## cpp代码2

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&(n&(n-1))==0;
    }
};
```

