/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include <string.h>
 typedef struct ListNode node;
bool isPalindrome(struct ListNode* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    node *fast=head,*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node *prev=NULL,*curr=slow,*temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    node *h1=head,*h2=prev;
    while(h2!=NULL){
        if(h1->val!=h2->val){
            return false;
        }
        h1=h1->next;
        h2=h2->next;
    }
    return true;
}