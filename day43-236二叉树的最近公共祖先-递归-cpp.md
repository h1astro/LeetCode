@[TOC](LeetCode-day43-236二叉树的最近公共祖先-递归-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/binarytree.png)

示例 1:

```
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

```


示例 2:

```
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
```

说明:

- 所有节点的值都是唯一的。
- p、q 为不同节点且均存在于给定的二叉树中。

## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetcod/)
> 时间复杂度: $O(N)$， 
> 空间复杂度$O(N)$，在堆栈使用的最坏情况下，每个节点的父指针字典和祖先集的空间为 $N$,斜二叉树的高度可能为 $N$
> 执行用时：$28 ms$

**递归**

不同于上一题的排序二叉树，不满足左节点<=当前节点<=右节点。

此题我们通过标记来寻找LCA，

LCA有三种情况

- p、q其一为LCA，另一个在LCA左边
- p、q其一为LCA，另一个在LCA右边
- p、q在LCA左右两边

于是定义三个left,right,mid

另外定义一个函数，然后需要在函数外定义用于存储LCA的变量

若寻找到该p或q对应值的node节点，标记该mid为1，但不要急着返回true，不一定要mid为1才是true，只要(mid+left+right)>0,即为真

如果left+right+mid>=2时，说明当前节点为LCA。

## cpp

```c++
#include<iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* LCA=new TreeNode(0);      //用于存储LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(findLCA(root,p,q)){
            return LCA;
        }
        return NULL;
    }
    bool findLCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if (root == NULL) {
            return false;
        }
        int left=(findLCA(root->left,q,p))?1:0; //判断在该下面获包括自身有要寻找的值
        int right=(findLCA(root->right,p,q))?1:0;
        int mid=0;
        if(root->val==p->val||root->val==q->val){   //当前节点值对应其中一个，
            mid=1;
        }
        if(left+right+mid>=2){          //关键！  如何判断找到LCA，父节点、左节点、右节点
            LCA=root;
        }
        return (left+right+mid)>0;      //只要其中一个为1，就为true
    }
};

int main(){
    Solution sol=Solution();
    TreeNode* node=new TreeNode(3);
    node->left=new TreeNode(5);
    node->right=new TreeNode(1);
    node->left->left=new TreeNode(6);
    node->left->right=new TreeNode(2);
    node->left->right->left=new TreeNode(7);
    node->left->right->right=new TreeNode(4);
    node->right->left=new TreeNode(0);
    node->right->right=new TreeNode(8);
    
    TreeNode* node1=new TreeNode(6);
    TreeNode* node2=new TreeNode(4);
    // expect result is  5
    TreeNode* node_res=sol.lowestCommonAncestor(node,node1,node2);
    cout<<node_res->val;
    
    return 0;
}
```

