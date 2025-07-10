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
    bool check(TreeNode *root,int target,int currsum){
        if(root==nullptr){return 0;}
        currsum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(currsum==target){
                return true;
            }
            else{
                return false;
            }
        }
        return check(root->left,target,currsum) || check(root->right,target,currsum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,targetSum,0);
    }
};