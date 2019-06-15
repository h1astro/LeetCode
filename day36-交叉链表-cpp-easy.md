@[TOC](LeetCode-day36-交叉链表-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/sort-list/)

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190615091151684.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQyMTQ2NjMw,size_16,color_FFFFFF,t_70)
在节点 c1 开始相交。

 

示例 1：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190615091208319.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQyMTQ2NjMw,size_16,color_FFFFFF,t_70)

```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```

示例 2：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190615091217895.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQyMTQ2NjMw,size_16,color_FFFFFF,t_70)
```
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```

示例 3：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190615091227414.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQyMTQ2NjMw,size_16,color_FFFFFF,t_70)
```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
```

注意：

> 如果两个链表没有交点，返回 null.
> 在返回结果后，两个链表仍须保持原有的结构。
> 可假定整个链表结构中没有循环。
> 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存

## 题解

> 参考[题解](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-bnw7cgeofh/)
> 时间复杂度: $O(m+n)$， 
> 执行用时：$56 ms$ 

**交叉链表**

可能对示例 2有疑惑,为什么不是从1开始而是从8呢,原因这边是找相同的地址,不是找值$val$.

一开始可能会想通过数组来存储,但是感觉不太行.

需要找出的是后面几段一样的,我们可以通过控制使两个链表长度一样,然后再遍历.

给的题目链表长度不一样? 可以使长的向后移几个位置.

## cpp代码

```c++
#include<iostream>
#include<vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_len=0;
        int b_len=0;
        ListNode* pA=headA;
        ListNode* pB=headB;
        while(pA){		//计算长度
            a_len++;
            pA=pA->next;
        }
        while(pB){
            b_len++;
            pB=pB->next;
        }
        if(a_len>b_len){	//长的一端,向后移动a_len-b_len,直到两段长度相等
            for(int i=0;i<a_len-b_len;i++){
                headA=headA->next;
            }
        }
        else{
            for(int i=0;i<b_len-a_len;i++){
                headB=headB->next;
            }
        }
        while(headA&&headB){
            if(headA==headB){ //比较的是地址是否相等，不是值相不相等
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

```
