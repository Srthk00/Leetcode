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
    bool bs(vector<int> &nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){return true;}
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(),nums.end());
        while(head!=nullptr && bs(nums,head->val)){
            head=head->next;
        }
        ListNode *temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            while(temp!=nullptr && temp->next!=nullptr && bs(nums,temp->next->val)){
                ListNode *temp2=temp->next->next;
                temp->next=temp2;
            }
            temp=temp->next;
        }
        return head;
    }
};