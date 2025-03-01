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
 typedef struct ListNode Node;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node *i=head->next;
        Node *prev=head;
        while(i!=nullptr){
            if(i->val>=prev->val){
                prev=i;
                i=i->next;
            }
            else{
                if(head->val>i->val){
                    prev->next=i->next;
                    i->next=head;
                    head=i;
                    i=prev->next;
                }
                else{
                    Node *temp=head;
                    while(temp->next->val < i->val){
                        temp=temp->next;
                    }
                    prev->next=i->next;
                    i->next=temp->next;
                    temp->next=i;
                    i=prev->next;
                }
            }
        }
        return head;
    }
};