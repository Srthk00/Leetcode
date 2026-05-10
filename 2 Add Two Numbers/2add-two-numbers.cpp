/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* createnode(int value) {
        return new ListNode(value);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;
        ListNode *point=head;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode *temp=createnode(sum%10);
            carry=sum/10;
            if(head==NULL){
                head=temp;
                point=head;
            }
            else{
                point->next=temp;
                point=temp;
            }
        }
        return head;
    }
};