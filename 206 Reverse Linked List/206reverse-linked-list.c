/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *temp=reverseList(head->next);
    node *temp2=head->next;
    temp2->next=head;
    head->next=NULL;
    return temp;
}