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
    long long result=0;
    
    long long totalsum(TreeNode *root){
        if(root==nullptr){return 0;}
        long long left=totalsum(root->left);
        long long right=totalsum(root->right);
        return root->val+left+right;
    }

    long long func(TreeNode *root,long long total){
        if(root==nullptr){return 0;}
        long long left=func(root->left,total);
        long long right=func(root->right,total);
        long long subtreesum=root->val+left+right;
        result=max(result,subtreesum*(total-subtreesum));
        return subtreesum;
    }

    int maxProduct(TreeNode* root) {
        long long total=totalsum(root);
        func(root,total);
        return result%(int)(1e9+7);
    }
};