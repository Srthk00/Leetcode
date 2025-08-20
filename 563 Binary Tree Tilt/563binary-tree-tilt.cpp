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
    int result=0;
    int func(TreeNode *root){
        if(root==nullptr){return 0;}
        int left=func(root->left);
        int right=func(root->right);
        result+=abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        func(root);
        return result;
    }
};