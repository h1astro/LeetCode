@[TOC](LeetCode-day39-344反转字符串-双指针-easy-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/reverse-string/)

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

**示例 1：**

```
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```

**示例 2：**

```
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
```



## 题解

> 参考[题解](https://leetcode-cn.com/problems/reverse-string/)
> 时间复杂度: $O(\frac{n}{2})$， 
> 空间复杂度$O(1)$
> 执行用时：$8 ms$

**双指针思想**
一个头和一个尾进行交换，可以用O(1)的空间来作辅助换位置，也可以使用swap实现交换

## cpp 

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 方法一
        // int size=(int)(1+s.size())/2;
        // char c;
        // for(int i=0;i<size;i++){
        //     c=s[s.size()-i-1];
        //     s[s.size()-i-1]=s[i];
        //     s[i]=c;
        // }

		// 方法二
        int k=0,i=s.size()-1;
        while(k<i) swap(s[k++],s[i--]);
    }
};
```

