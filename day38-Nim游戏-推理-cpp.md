@[TOC](LeetCode-day38-Nim游戏-推理-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/nim-game/)

你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。

你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。

示例:

```
输入: 4
输出: false 
解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
     因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
```

## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/nim-game/solution/nimyou-xi-by-leetcode/)和[题解](https://leetcode-cn.com/problems/nim-game/solution/chao-xiang-xi-de-fen-xi-zhao-gui-lu-de-bu-zou-by-t/)
> 时间复杂度: $O(1)$， 
> 执行用时：$8 ms$

**推理**

一步步推，数学归纳法，当是4.8.12...的时候，即4倍数的时候，为false

## cpp sort

```c++
class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0)return false;
        return true;
    }
};
```

