/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> vp,vq;

    bool findp(TreeNode *root,TreeNode *p){
        if(root==nullptr){return false;}
        if(root==p){vp.push_back(root);return true;}
        if(findp(root->left,p) || findp(root->right,p)){
            vp.push_back(root);
            return true;
        }
        return false;
    }

    bool findq(TreeNode *root,TreeNode *q){
        if(root==nullptr){return false;}
        if(root==q){vq.push_back(root);return true;}
        if(findq(root->left,q) || findq(root->right,q)){
            vq.push_back(root);
            return true;
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findq(root,q);
        findp(root,p);
        unordered_map<TreeNode*,int> mp;
        for(int i=0;i<vp.size();i++){
            mp[vp[i]]=vp[i]->val;
        }
        for(int i=0;i<vq.size();i++){
            if(mp.find(vq[i])!=mp.end()){return vq[i];}
        }
        return root;
    }
};