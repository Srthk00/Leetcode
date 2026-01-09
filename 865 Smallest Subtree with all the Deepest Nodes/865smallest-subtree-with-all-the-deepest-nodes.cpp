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
    // node: depth
    unordered_map<TreeNode*,int> mp;
    int maxd=-1;

    void finddepth(TreeNode *root,int d){
        if(root==nullptr){return;}
        mp[root]=d;
        maxd=max(maxd,d);
        finddepth(root->left,d+1);finddepth(root->right,d+1);
    }

    bool find(TreeNode *root,TreeNode *q,vector<TreeNode*> &pth){
        if(root==nullptr){return false;}
        if(root==q){pth.push_back(root);return true;}
        if(find(root->left,q,pth) || find(root->right,q,pth)){
            pth.push_back(root);
            return true;
        }
        return false;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        finddepth(root,0);
        vector<TreeNode*> deepestnodes;
        for(auto &it:mp){
            if(it.second==maxd){
                deepestnodes.push_back(it.first);
            }
        }
        vector<vector<TreeNode*>> allpaths;
        for(auto &it:deepestnodes){
            vector<TreeNode*> temp;
            find(root,it,temp);
            allpaths.push_back(temp);
        }
        vector<TreeNode*> first=allpaths[0];
        for(auto *f:first){
            bool flag=true;
            for(int i=1;i<allpaths.size();i++){
                if(std::find(allpaths[i].begin(),allpaths[i].end(),f)==allpaths[i].end()){
                    flag=false;
                }
            }
            if(flag){return f;}
        }
        return root;
    }
};