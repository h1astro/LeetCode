@[TOC](LeetCode-字符串转换整数atoi)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/reverse-integer/)
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

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

> **注意:** 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 $[−2^{31},  2^{31} − 1]$。请根据这个假设，如果反转后整数溢出那么就返回 0。

## 题解

> 时间复杂度是 $O(n)$
> 空间复杂度$O(1)$
> 执行用时：$16 ms$

此题比较简单，左边的一直出现的空格要跳过，然后注意int31的范围，不能超过了。我处理负数是最后再加上"-"。

> 主要是要注意一些用例

- "+ -9"    
  - 0     连续的正负号问题
- “+9”
  - 9     有出现＋
- “ 9.13”
  - 9     小数点问题，只返回整数部分
- "661dnf56"
  - 661   间断的数字
- "dfak99"
  - 0  数字前不能出现那类字符



## cpp 代码实现

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int len=str.length();
        int num=0;
        int flag_negative=0;    //判断是否为负数
        int flag_first=0;       //是否在出现数字和±或者空格之前没有有其它字符出现
        for(int i=0;i<len;i++){
            //防+-345的连续两个字符的出现
            if(str[i]==32||((str[i]==45||str[i]==43)&&(str[i+1]>=48&&str[i]<=57)))continue;   
     		//'.'小数点
            else if(str[i]==46&&str[i+1]>=48&&str[i+1]<=57&&str[i-1]>=48&&str[i-1]<=57){ 		
                return num;
            }
            else if(str[i]>=48&&str[i]<=57){
                flag_first=1;
                if(i>0&&str[i-1]==45) flag_negative=1;   //为负数
                if(flag_negative==0){
                    if(num>INT_MAX/10|| num==INT_MAX/10&&str[i]>55){  //55->'7'
                        return pow(2,31)-1;
                    }
                }
                if(flag_negative==1){
                    if(num>INT_MAX/10|| num==INT_MAX/10&&str[i]>=56){ //55->'8'
                        return -pow(2,31);
                    }
                }
                num=num*10+((int)str[i]-48);
                if(i+1<len&&(str[i+1]>57||str[i+1]<48)){
                    if(flag_negative==1)return -num;
                    return num;
                }
            }
            else {
                if(flag_first==0){
                    return 0;
                }
            }
        }
        if(flag_negative==1)return -num;
        return num;
    }
};
```

## python正则匹配 

> 搬运py使用正则匹配 [\[题解\]](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/python-1xing-zheng-ze-biao-da-shi-by-knifezhu/)

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        return max(min(int(*re.findall('^[\+\-]?\d+', s.lstrip())), 2**31 - 1), -2**31)
```

使用正则表达式：

```
^：匹配字符串开头
[\+\-]：代表一个+字符或-字符
?：前面一个字符可有可无
\d：一个数字
+：前面一个字符的一个或多个
\D：一个非数字字符
*：前面一个字符的0个或多个
```

`max(min(数字, 2**31 - 1), -2**31)` 用来防止结果越界
