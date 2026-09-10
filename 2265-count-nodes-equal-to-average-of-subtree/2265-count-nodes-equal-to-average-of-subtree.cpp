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
    pair<int,int> traverse(TreeNode *root){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int> left=traverse(root->left);
        pair<int,int> right=traverse(root->right);
        int sum=left.first+right.first+root->val;
        int count=left.second+right.second+1;
        if(root->val==sum/count){
            result++;
        }
        return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return result;
    }
};