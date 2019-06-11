
@[TOC](LeetCode-day31-反转链表-迭代-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

反转一个单链表。

示例:

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？





## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/)，未实现方法二-递归
> 时间复杂度: $O(n)$， 
> 空间复杂度: $O(1)$
> 执行用时：$12 ms$ 

**迭代**

假设存在链表 1 → 2 → 3 → Ø，我们想要把它改成 Ø ← 1 ← 2 ← 3。

在遍历列表时，将当前节点的 next 指针改为指向前一个元素。由于节点没有引用其上一个节点，因此必须事先存储其前一个元素。在更改引用之前，还需要另一个指针来存储下一个节点。不要忘记在最后返回新的头引用！



## cpp代码

```c++
#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* rail=NULL;
        while(curr!=NULL){
            ListNode* nextNode=curr->next;  //存储下一个节点
            curr->next=rail;                //接上尾部
            rail=curr;                      //更新尾部
            curr=nextNode;                  //更新当前curr
        }
        return rail;
    }
};


int main(){
    Solution sol=Solution();
    ListNode* node=new ListNode(5);
    node->next=new ListNode(4);
    node->next->next=new ListNode(3);
    node->next->next->next=new ListNode(2);

    ListNode* newNode=sol.reverseList(node);

    return 0;
}
```
