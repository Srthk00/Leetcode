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
    int getDecimalValue(ListNode* head) {
        string str="";
        while(head!=nullptr){
            str+=to_string(head->val);
            head=head->next;
        }
        long long result=0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='1'){
                result+=pow(2,str.size()-i-1);
            }
        }
        return (int)result;
    }
};