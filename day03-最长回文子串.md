#LeetCode-最长回文子串
## 题目回顾
[传送门](https://leetcode-cn.com/problems/longest-palindromic-substring/)
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
```
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
```
示例 2：
```
输入: "cbbd"
输出: "bb"
```

## 题解
>参考动态规划[\[题解\]](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-c-by-gpe3dbjds1/)
时间复杂度是 $O(n^2)$
执行用时：$400 ms$

使用动态规划思想，开辟$N*N$个空间，即$dp[n][n]$。首先只有一个符号的为1，即对角线的都为1，表示只有本身一个为字符串的情况。
$dp$解释：
$$
dp[i][j]=\left\{
\begin{aligned}
true & ,s[i]...s[j]都为回文 \\
false & ,不是回文 \\
\end{aligned}
\right.
$$

判断条件：
$$
dp[i][j]=(dp[i+1][j-1] \quad and  \quad S_i == S_j)
$$

之后每次循环递增回文长度，start记录开始位置，max记录最大回文长度。
>注意数组越界的情况

## cpp 代码实现
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
    int len=s.length();        
    if(len<=1){
        return s;
    }
    int max=1;
    int start;

    vector<vector<int>>  P(len,vector<int>(len));//定义二维动态数组
	for(int i=0;i<len;++i){
        P[i][i]=1;
        if(i+1<len&&s[i]==s[i+1]){
            P[i][i+1]=1;
             max=2;
            start=i;
        }
    }
    int j;
    for(int L=3;L<=len;L++){  //L表示找是否存在该回文长度
        for(int i=0;i<len;i++){
            j=L+i-1;    
            if(j-1<0||j>len||i+1>=len)continue;  //越界处理
            if(P[i+1][j-1]==1&&s[i]==s[j]){   //如果左右两个相同和之间的都为1                   
                P[i][j]=1;
                max=L;
                start=i;
            }
        }
    }

    return s.substr(start,max);
    }
};
```
