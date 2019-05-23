# 个人题解 https://blog.csdn.net/qq_42146630/article/details/90056570
@[TOC](LeetCode-两数相加)
## 题目回顾
[传送门](https://leetcode-cn.com/problems/add-two-numbers/)
给出两个 **非空** 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

## 题解
参考 [\[官方题解\]](https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode/)
~~不要在把链表中的每个数读出来，得出每个链表里的实际值的大小,然后将得到的sum，再换算到新链表里存储~~
新建一个链表，开始赋值为0，每读取每个链表里的一个数之和就进行存储。
对两个输入的链表进行遍历读取，两个数之和再加上上一轮的进位值，对个位数进行保存到下一个节点值，若有进位，该进位数用于下一轮循环。
>注意点，如果两个链表长度不同，如果为空，就对空的值赋0，防止报错。
>最后遍历完，还要判断是否最后一次有进位，如果有，还需要再创建一个结点，扩展了链表的总长度。


 ## cpp 代码实现
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nodes=new ListNode(0);
        ListNode* head=nodes;
        int sum;
        int carry=0; //表示进位
        int x,y;
        while(l1!=NULL||l2!=NULL){
            x=l1!=NULL?l1->val:0;    //防止报错，当前的l1或l1为空
            y=l2!=NULL?l2->val:0;
            sum=carry+x+y;
            carry=sum/10;
            sum=sum%10;
            nodes->next=new ListNode(sum);
            nodes=nodes->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if(carry==1) nodes->next=new ListNode(carry); //数最前面两位如果进位，需要再开辟一个节点
        return head->next;
    }
};
```

## python 代码实现
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry=0
        nodes=ListNode(0)
        head=nodes
        while l1 or l2:
            num1=l1.val if l1 else 0
            num2=l2.val if l2 else 0
            sum=num1+num2+carry
            carry=sum//10
            nodes.next=ListNode(sum%10)
            nodes=nodes.next
            l1=l1.next if l1 else None
            l2=l2.next if l2 else None
            
        if carry==1:
            nodes.next=ListNode(1)
        return head.next
```
