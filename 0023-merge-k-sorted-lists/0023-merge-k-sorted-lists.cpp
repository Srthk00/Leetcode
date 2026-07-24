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
    typedef ListNode node;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return nullptr;
        }
        vector<pair<int,node*>> temp;
        for(int i=0;i<n;i++){
            node *head=lists[i];
            while(head){
                temp.push_back({head->val,head});
                head=head->next;
            }
        }
        sort(temp.begin(),temp.end());
        if(temp.size()==0){
            return nullptr;
        }
        node *result=temp[0].second;
        node *curr=result;
        for(int i=1;i<temp.size();i++){
            curr->next=temp[i].second;
            curr=curr->next;
        }
        curr->next=nullptr;
        return result;
    }
};