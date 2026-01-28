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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            head=NULL;
        return head;
        }
        ListNode *point=head;
        int count=0;
        while(point!=NULL){
            count++;
            point=point->next;
        }
        if(count==n){
            ListNode *temp=head;
            head=head->next;
            return head;
        }
        point=head;
        count=count-n;
        while(count>1){
            point=point->next;
            count--;
        }
        ListNode *temp=point->next;
        point->next=point->next->next;
        return head;
    }
};