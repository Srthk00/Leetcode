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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode *temp=head;
        while(temp!=nullptr){
            n++;temp=temp->next;
        }
        if(n==0 || n==1){return head;}
        k%=n;
        if(k==0){return head;}
        ListNode *last=head;
        while(last->next!=nullptr){
            last=last->next;
        }
        int move=n-k-1;
        temp=head;
        while(move>0){
            move--;
            temp=temp->next;
        }
        last->next=head;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};