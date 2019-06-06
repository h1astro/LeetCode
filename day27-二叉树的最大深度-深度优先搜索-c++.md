@[TOC](LeetCode-day27-二叉树的最大深度-深度优先搜索-c++)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree)

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

**示例：**
给定二叉树 `[3,9,20,null,null,15,7]`，

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。



## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-leetcode/)和[题解代码](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-gpe3dbjds1/)
> 时间复杂度是$O(n)$， 
> 空间复杂度：在最糟糕的情况下，树是完全不平衡的，例如每个结点只剩下左子结点，递归将会被调用 NN 次（树的高度），因此保持调用栈的存储将是O(N)。但在最好的情况下（树是完全平衡的），树的高度将是 log(N)。因此，在这种情况下的空间复杂度将是O(log(N))。
> 执行用时：$20 ms$ 

**深度优先搜索 递归**

从顶点开始找左右子树中层数最大的，左子树中找该左右子树最大的，...依次寻找下去

直到为空返回0，递推公式 $1+max(maxDepth(root->left),maxDepth(root->right))$

![img](https://pic.leetcode-cn.com/Figures/104/104_slide_4.png)

![img](https://pic.leetcode-cn.com/Figures/104/104_slide_7.png)

![img](https://pic.leetcode-cn.com/Figures/104/104_slide_10.png)



## cpp代码

```python
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
       int depth=0;
       if(root==NULL){
           return 0;
       } 
       else{
            depth=max(maxDepth(root->left),maxDepth(root->right));
            return 1+depth;
       }
    }
};
```



