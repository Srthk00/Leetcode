/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *point1=head,*point2=head->next;
    point1->next=point2->next;
    point2->next=point1;
    head=point2;
    point1->next=swapPairs(point1->next);
    return head;
}