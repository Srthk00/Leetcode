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
    vector<string> result;
    void dfs(TreeNode *root,string str){
        if(!root){return;}
        if(!root->left && !root->right){
            result.push_back(str+"->"+to_string(root->val));
            return;
        }
        dfs(root->left,str+"->"+to_string(root->val));
        dfs(root->right,str+"->"+to_string(root->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str=to_string(root->val);
        if(!root->left && !root->right){
            result.push_back(str);
        }
        dfs(root->left,str);
        dfs(root->right,str);
        return result;
    }
};