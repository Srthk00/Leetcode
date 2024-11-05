/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL)
        return head;

    while(head!=NULL && head->val==val)
        head=head->next;

    node *point=head,*prev=head;
    while(point!=NULL){
        if(point->val==val){
            prev->next=point->next;
            point=point->next;
        }
        else{
            prev=point;
            point=point->next;
        }
    }
    return head;
}