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
        vector<node*> idx(n,nullptr);
        for(int i=0;i<n;i++){
            idx[i]=lists[i];
        }
        node *result=nullptr;
        node *curr=nullptr;
        while(true){
            bool found=false;
            int mini=1e9;
            int t=-1;
            for(int i=0;i<n;i++){
                if(idx[i] && idx[i]->val<mini){
                    found=true;
                    mini=idx[i]->val;
                    t=i;
                }
            }
            if(!found){
                break;
            }
            else{
                node *temp=idx[t];
                idx[t]=temp->next;
                if(!result){
                    result=temp;
                    curr=temp;
                    curr->next=nullptr;
                }
                else{
                    curr->next=temp;
                    curr=temp;
                    curr->next==nullptr;
                }
            }
        }
        return result;
    }
};