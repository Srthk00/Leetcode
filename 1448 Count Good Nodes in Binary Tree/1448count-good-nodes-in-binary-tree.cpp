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
    int count(TreeNode *root,int maxi){
        if(root==nullptr){
            return 0;
        }
        if(root->val>=maxi){
            return 1+count(root->left,max(maxi,root->val))+count(root->right,max(maxi,root->val));
        }
        else{
            return count(root->left,max(maxi,root->val))+count(root->right,max(maxi,root->val));
        }
    }

    int goodNodes(TreeNode* root) {
        return 1+count(root->left,root->val)+count(root->right,root->val);
    }
};