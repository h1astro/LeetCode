@[TOC](LeetCode-[合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

**示例：**

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

## 题解

> 参考[题解](https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-powcai/)
> 时间复杂度是 $O(m+n)$
> 空间复杂度$O(m+n)$
> 执行用时：$68 ms$

**迭代方法**

建一个新的链表，然后注意比较两个链表头的大小，小值的就存入新链表中，该小值的链表指向下一个，依次循环直到为空。



## py 代码实现

```python
class Solution:
    def mergeTwoLists(self, l1, l2):
        nodes = ListNode(0)
        p = nodes
        while l1 or l2:
            if l1 and l2:
                tmp1 = l1.val
                tmp2 = l2.val
                if tmp1 < tmp2:
                    p.next = ListNode(tmp1)
                    l1 = l1.next
                else:
                    p.next = ListNode(tmp2)
                    l2 = l2.next
            elif l1:
                p.next = ListNode(l1.val)
                l1 = l1.next
            elif l2:
                p.next = ListNode(l2.val)
                l2 = l2.next
            p = p.next
        return nodes.next
```

