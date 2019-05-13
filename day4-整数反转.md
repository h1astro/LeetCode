@[TOC](LeetCode-整数反转)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/reverse-integer/)给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

**示例 1:**

```
输入: 123
输出: 321
```

 **示例 2:**

```
输入: -123
输出: -321
```

**示例 3:**

```
输入: 120
输出: 21
```

> **注意:**假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 $[−2^{31},  2^{31} − 1]$。请根据这个假设，如果反转后整数溢出那么就返回 0。

## 题解

> 参考[\[题解\]](https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-c-by-gpe3dbjds1/)
> 时间复杂度是 $O(n)$
> 空间复杂度$O(1)$
> 执行用时：$4 ms$

~~不需要把整数转换为字符转来反转，也不用考虑为反转前最后连续的几个都是0，反过来没影响~~

$pop=x\%10,x=x/10$获取末尾数字

$rev=rev*10+pop$来反转

但是需要考虑反转的时候溢出的情况，对于有符号的int32位的范围为 $-2^{31}=-2147483648,2^{31}-1=2147483647$，主要检查反转时的最后一位和倒数第二位。

如果$x$为正数，

当前的$rev>\frac{INTMAX}{10}$时，$rev=rev*10+pop$将超过$2^{31}-1$，溢出，

或者$rev==\frac{INTMAX}{10} \quad and \quad pop>7$时，也将超过$2^{31}-1$,溢出。所以如果出现溢出的情况，我们$return 0$。

如果$x$为负数情况类似。

## cpp 代码实现

```cpp
class Solution {
public:
    int reverse(int x) {
        int rev=0;//存放反转后的数
        int pop=0;//存放弹出的数
        while(x!=0)
        {
            pop=x%10;
            x=x/10;
            if(rev>INT_MAX/10||rev==INT_MAX/10&&pop>7){
                return 0;
            }
            if(rev<INT_MIN/10||rev==INT_MIN/10&&pop<-8){
                return 0;
            }
            rev=rev*10+pop;
        }
        return rev;
    }
};
```
