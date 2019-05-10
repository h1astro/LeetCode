# 个人题解 https://blog.csdn.net/qq_42146630/article/details/90056570
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
