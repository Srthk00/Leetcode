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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        for(auto &it:descriptions){
            int p=it[0],c=it[1],left=it[2];
            if(mp.count(p)){
                if(mp.count(c)){
                    left?mp[p]->left=mp[c]:mp[p]->right=mp[c];
                }
                else{
                    TreeNode *tempC=new TreeNode(c);
                    mp[c]=tempC;
                    left?mp[p]->left=tempC:mp[p]->right=tempC;
                }
            }
            else{
                TreeNode *tempP=new TreeNode(p);
                mp[p]=tempP;
                if(mp.count(c)){
                    left?tempP->left=mp[c]:tempP->right=mp[c];
                }
                else{
                    TreeNode *tempC=new TreeNode(c);
                    mp[c]=tempC;
                    left?tempP->left=tempC:tempP->right=tempC;
                }
            }
        }
        unordered_set<int> root;
        int n=descriptions.size();
        for(int i=0;i<n;i++){
            root.insert(descriptions[i][0]);
        }
        for(int i=0;i<n;i++){
            int t=descriptions[i][1];
            if(root.count(t)){
                root.erase(t);
            }
        }
        int result;
        for(auto &it:root){
            result=it;
        }
        return mp[result];
    }
};