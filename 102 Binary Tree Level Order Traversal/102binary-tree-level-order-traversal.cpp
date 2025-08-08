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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){return {};}
        vector<vector<int>> result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int s=que.size();
            vector<int> tempvec;
            while(s-->0){
                TreeNode *temp=que.front();
                que.pop();
                tempvec.push_back(temp->val);
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            result.push_back(tempvec);
        }
        return result;
    }
};