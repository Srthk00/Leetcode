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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *p=head,*c=head->next,*point=head;
        while(c!=NULL){
            if(c->val!=p->val){
                p=c;
                c=c->next;
            }
            else{
                if(c->next==NULL){
                    p->next=NULL;
                    return head;
                }
                point=c;
                p->next=c->next;
                c=c->next;
            }
        }
        return head;
    }
};