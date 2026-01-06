/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int result=1;
        int level=1;
        int max_sum=root->val,curr_sum=root->val;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int s=que.size();
            curr_sum=0;
            while(s-->0){
                TreeNode *temp=que.front();
                que.pop();
                curr_sum+=temp->val;
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            if(max_sum<curr_sum){
                max_sum=curr_sum;
                result=level;
            }
            level++;
        }
        return result;
    }
};