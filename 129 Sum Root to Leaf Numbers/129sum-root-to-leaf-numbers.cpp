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
    void generate(TreeNode *root,string str){
        if(root==nullptr){
            return;
        }
        if(!root->left && !root->right){
            str+=to_string(root->val);
            result+=stoi(str);
        }
        generate(root->left,str+to_string(root->val));
        generate(root->right,str+to_string(root->val));
    }
    int sumNumbers(TreeNode* root) {
        generate(root,"");
        return result;
    }
};