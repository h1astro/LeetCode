@[TOC](LeetCode-day41-557反转字符串中的单词III-双指针-easy-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

```
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
```

注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。



## 题解

> 时间复杂度: $O(n)$， 
> 空间复杂度$O(1)$
> 执行用时：$24 ms$

**双指针思想**

和字符串转换I那题类似，这里只是多了一个判断空格的地方，然后再得知头尾两端的下标

一个头和一个尾进行交换，可以用O(1)的空间来作辅助换位置

## cpp

```c++
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len=s.length();
        int head=0;
        int rail=0;
        for(int i=0;i<len;i++){
            if(s[i]==32){                   //判断是否为空格
                rail=i-1;                   //更新尾部
                reverseString(s,head,rail); //进行反转
                head=i+1;                   //更新头部
            }
        }
        if(head<s.length()){
            reverseString(s,head,s.length()-1); //最后一段处理
        }
        return s;
    }
    void reverseString(string &s,int head,int rail) {
        int size=(int)(1+rail-head)/2;
        char c;  
        for(int i=head;i<head+size;i++){
            
            c=s[head+rail-i];
            s[head+rail-i]=s[i];
            s[i]=c;
        }
    }
};

int main(){

    Solution sol=Solution();

    string s="dfag dkfja df abnd";

    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    cout<<endl;
    string s2=sol.reverseWords(s);
    for(int i=0;i<s2.size();i++){
        cout<<s2[i];
    }
    // result is :
    // gafd ajfkd fd dnba
    return 0;
}
```

