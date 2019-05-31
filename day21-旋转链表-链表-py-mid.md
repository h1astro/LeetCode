@[TOC](LeetCode-[136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/rotate-list/)

给定一个链表，旋转链表，将链表每个节点向右移动 *k* 个位置，其中 *k* 是非负数。

**示例 1:**

```
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
```

**示例 2:**

```
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```



## 题解

> 参考[官方题解](https://leetcode-cn.com/problems/rotate-list/solution/xuan-zhuan-lian-biao-by-leetcode/)
> 时间复杂度是 $O(n)$， 
> 空间复杂度$O(1)$,
> 执行用时：$56 ms$ 

1. 确定链表的长度，并找到尾节点
2. 接链表连成环，既将尾节点连接上头节点，
3. 根据位置，然后找要断开的位置，链表长度n-k%n
4. 重新定义头节点和尾节点

> 注意：1.输入为空时，返回None；2.输入为一个数时，直接返回该数

## python 实现

```python
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None 

class Solution:
    def rotateRight(self,  head, k):
        if not head:    #为空返回None
            return None
        cur=head
        count=1
        while cur.next!=None:       #遍历长度
            cur=cur.next
            count=count+1
            if cur.next==None:
                cur.next=head       #将首尾结合 变成一个环
                break
        k=count-k%count
        if k==count  or count==1:       #如果刚好为原地 或者 本来链表里就只有一个数
            cur.next=None
            return head
        cur=head            
        for i in range(1,count+1):
            if i==k:                    #寻找到相关的位置
                head=cur.next           #重新定义当前的链表头
                cur.next=None           #将环拆开 定义尾部  
                return head                                 
            cur=cur.next
        return head
             
if __name__=='__main__':
    sol=Solution()  
    num=ListNode(3)
    num.next=ListNode(4)
    num.next.next=ListNode(5)
    num.next.next.next=ListNode(6)

    k=7
    head=sol.rotateRight(num,k)
    while 1:
        print(head.val)
        head=head.next
        if head==None:
            break
```

