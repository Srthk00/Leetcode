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
    vector<int> nodes;
    void inorder(TreeNode *root){
        if(root==nullptr){return;}
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *makeBalance(int i,int j){
        if(i>j){return nullptr;}
        int mid=i+(j-i)/2;
        TreeNode *left=makeBalance(i,mid-1);
        TreeNode *right=makeBalance(mid+1,j);
        return new TreeNode(nodes[mid],left,right);
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        TreeNode *result=makeBalance(0,nodes.size()-1);
        return result;
    }
};