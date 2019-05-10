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
