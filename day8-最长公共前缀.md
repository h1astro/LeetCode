@[TOC](LeetCode-最长公共前缀)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/longest-common-prefix/)

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 `""`。

**示例 1:**

```
输入: ["flower","flow","flight"]
输出: "fl"
```

**示例 2:**

```
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
```

**说明:**

所有输入只包含小写字母 `a-z` 。



## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/longest-common-prefix/solution/zui-chang-gong-gong-qian-zhui-by-leetcode/) 和 [python代码](https://leetcode-cn.com/problems/longest-common-prefix/solution/duo-chong-si-lu-qiu-jie-by-powcai-2/)
> 时间复杂度是 $O*(*S)，S $是所有字符串中字符数量的总和。
> 空间复杂度$O(1)$
> 执行用时：$ 56 ms$

**水平扫描法**

注意是找最长的**前缀**，需要循环遍历每个字符串，第一个的和第二个的比较，如果不一样，就第二个字符串数减一再比较，如果相同就遍历下一个字符串。

![æ¾å°æé¿å
¬å
±åç¼](https://pic.leetcode-cn.com/b647cab7c3d2bd157cecae10917e0b9b671756b92c9cfcefec1a2bdae299c11c-file_1555694071243)



## python代码实现

```python
class Solution:
    # def longestCommonPrefix(self, strs: List[str]):
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        
        common=strs[0]
        i=1
        while i<len(strs):
            while strs[i].find(common)!=0:
                common=common[0:len(common)-1]
            i=i+1
        return common
```

