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
    void buildgraph(TreeNode *root,TreeNode *prev,unordered_set<TreeNode*> &leaf,unordered_map <TreeNode*,vector<TreeNode*>> *graph){
            if(root==NULL){return;}
            if(root->left==NULL && root->right==NULL){
                leaf.insert(root);
            }
            if(prev!=NULL){
                (*graph)[root].push_back(prev);
                (*graph)[prev].push_back(root);
            }
            buildgraph(root->left,root,leaf,graph);
            buildgraph(root->right,root,leaf,graph);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leaf;
        buildgraph(root,NULL,leaf,&graph);
        int count=0;
        for(auto *l:leaf){
            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(l);
            visited.insert(l);
            for(int i=0;i<=distance;i++){
                int s=que.size();
                while(s-->0){
                    TreeNode *node=que.front();
                    que.pop();
                    if(leaf.count(node) && node!=l){
                        count++;
                    }
                    for(auto &v:graph[node]){
                        if(!visited.count(v)){
                            que.push(v);
                            visited.insert(v);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};