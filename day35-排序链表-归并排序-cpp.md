@[TOC](LeetCode-day35-排序链表-归并排序-cpp)

## 题目回顾

[传送门](https://leetcode-cn.com/problems/sort-list/)

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

```
输入: 4->2->1->3
输出: 1->2->3->4
```

示例 2:

```
输入: -1->5->3->4->0
输出: -1->0->3->4->5
```



## 题解

> 参考[题解](https://blog.csdn.net/qq_41855420/article/details/87901524)
> 时间复杂度$O(n(log_n))$
> 执行用时：$112 ms$ 

思路分析：常见排序方法有很多，插入排序，选择排序，堆排序，快速排序，冒泡排序，归并排序，桶排序等等。由于题目特意要求 **O(n log n) 时间复杂度和常数级空间复杂度** 所以不能使用冒泡、计数排序啥的，比较符合要求的就是归并排序。
归并排序：排序一段序列分为排序前部分、后部分，再合并两个已经排序好的部分。

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
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		return mergeSort(head);//去掉链表尾端的寻找
	}
	ListNode* mergeSort(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *fast=head->next;
        ListNode *slow=head;
        //找中点
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next;                    //这里而不是直接fast=fast->next->next
            slow=slow->next;
            if(fast!=NULL&&fast->next!=NULL){   //这样解决保证每次都是遍历到最后一个      
                fast=fast->next;
            }
        }

        //归并
        ListNode* rightList=mergeSort(slow->next);
        slow->next=NULL;
        ListNode* leftList=mergeSort(head);

        ListNode *pHead=NULL;
        ListNode *pEnd=NULL;
        if(rightList==NULL){
            return leftList;
        }    
        if(rightList->val>leftList->val){
            pEnd=pHead=leftList;
            leftList=leftList->next;
        }
        else{
            pEnd=pHead=rightList;
            rightList=rightList->next;
        }
        //合并，每次将最小值放入链表
        while(rightList&&leftList){
            if(rightList->val<leftList->val){
                pEnd->next=rightList;
                rightList=rightList->next;
            }
            else{
                pEnd->next=leftList;
                leftList=leftList->next;
            }
            pEnd=pEnd->next;
        }
        if(rightList){
            pEnd->next=rightList;
        }
        else if(leftList){
            pEnd->next=leftList;
        }
        return pHead;
    }
};

int main(){

    Solution sol=Solution();
    ListNode* node=new ListNode(5);
    node->next=new ListNode(4);
    node->next->next=new ListNode(3);
    node->next->next->next=new ListNode(2);

    ListNode* newNode=sol.sortList(node);
    while(newNode){
        cout<<newNode->val<<" ";
        newNode=newNode->next;
    }
    return 0;
}
```
