/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode node;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;

    node *head=NULL;
    if(list1->val<=list2->val){
        head=list1;
        list1=list1->next;
    }
    else{
        head=list2;
        list2=list2->next;
    }

    node *point=head;
    while(list1!=NULL && list2!=NULL){

        if(list1->val<=list2->val){
            point->next=list1;
            list1=list1->next;
        }
        else{
            point->next=list2;
            list2=list2->next;
        }
        point=point->next;
    }
    if(list1!=NULL){
        point->next=list1;
    }
    else{
        point->next=list2;
    }
    return head;
}