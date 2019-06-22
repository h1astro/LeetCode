@[TOC](LeetCode-day42-235二叉搜索树的最近公共祖先-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190622225840831.png)
示例 1:

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
```

解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
```

解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

说明:

- 所有节点的值都是唯一的。
- p、q 为不同节点且均存在于给定的二叉搜索树中。

## 题解

> 参考[题解](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/40msgo-shi-xian-by-elliotxx/)->理解题意思路和[题解c++](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/zui-jin-gong-gong-zu-xian-cti-jie-by-tensor-2/)->将递归换成l了while
> 时间复杂度: $O(n)$， 
> 空间复杂度$O(1)$
> 执行用时：$44 ms$

由于是排序二叉树，所以一定满足左节点<=当前节点<=右节点。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        bool flag=true;
        while(flag){    //根据二叉树的性质 直到找到大小存在于两者之间的
            if(p->val>root->val&&q->val>root->val){     
                root=root->right;
            }
            else if(p->val<root->val&&q->val<root->val){
                root=root->left;
            }
            else{
                flag=false;
            }
        }
        return root;
    }
};

int main(){

    Solution sol=Solution();
    TreeNode* node=new TreeNode(6);
    node->left=new TreeNode(2);
    node->right=new TreeNode(8);
    node->left->left=new TreeNode(0);
    node->left->right=new TreeNode(4);
    node->left->right->left=new TreeNode(3);
    node->left->right->right=new TreeNode(5);
    node->right->left=new TreeNode(7);
    node->right->right=new TreeNode(9);
    
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(4);

    TreeNode* node_res=sol.lowestCommonAncestor(node,node1,node2);
    cout<<node_res->val;
    // expect result is  2
    return 0;
}
```

## cpp 2

```c++
// wrong.. 
//input [2 ,1]  2 1 
//output 1
//expect 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(p->val>q->val){
            int cp=q->val;
            q->val=p->val;
            p->val=cp;
        }
        if(p->val<=root->val&&root->val<=q->val){
            return root;
        }
        else if(q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else{
            return lowestCommonAncestor(root->right,p,q);
        }
    }
};
```

