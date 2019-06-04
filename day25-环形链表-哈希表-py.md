
@[TOC](LeetCode-day25-环形链表-哈希表)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/subsets/)

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。



**示例 1：**

```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190603231257607.png)

**示例 2：**

```
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190603231313389.png)

**示例 3：**

```
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190603231329368.png)
## 题解

> 参考[题解](https://leetcode-cn.com/problems/linked-list-cycle/solution/huan-xing-lian-biao-python3zhi-jie-fa-by-pandawaka/)
> 时间复杂度是O(n)， 
> 空间复杂度O(n),
> 执行用时：$52 ms$ 

**哈希表**

用容器存储起来，判断有没有重复。

## py代码

```python
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        
        target = {head}
        head =head.next
        while head:
            if head in target:
                return True
            else:
                target.add(head)
                head = head.next
        return False
```
