/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode node;
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL){
        return NULL;
    }
    node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}