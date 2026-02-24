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

    void solve(TreeNode* root, string num) {
        if(root==nullptr){return;}
        string str=num+to_string(root->val);
        if(!root->left && !root->right){
            result+=stoi(str,nullptr,2);
            return;
        }
        solve(root->left,str);
        solve(root->right,str);
    }

    int sumRootToLeaf(TreeNode* root) {
        solve(root,"");
        return result;
    }
};