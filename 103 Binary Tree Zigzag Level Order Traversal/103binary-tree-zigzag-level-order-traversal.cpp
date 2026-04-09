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
    typedef TreeNode node;

    vector<vector<int>> zigzagLevelOrder(node* root) {
        if(root==nullptr){
            return {};
        }
        stack<node*> left,right;
        right.push(root);
        vector<vector<int>> result;
        int level=0;
        while(!left.empty() || !right.empty()){
            if((level%2)==0){
                vector<int> res;
                while(!right.empty()){
                    node *top=right.top();
                    right.pop();
                    res.push_back(top->val);
                    if(top->left){
                        left.push(top->left);
                    }
                    if(top->right){
                        left.push(top->right);
                    }
                }
                result.push_back(res);
                level++;
            }
            else{
                vector<int> res;
                while(!left.empty()){
                    node *top=left.top();
                    left.pop();
                    res.push_back(top->val);
                    if(top->right){
                        right.push(top->right);
                    }
                    if(top->left){
                        right.push(top->left);
                    }
                }
                result.push_back(res);
                level++;
            }
        }
        return result;
    } 
};