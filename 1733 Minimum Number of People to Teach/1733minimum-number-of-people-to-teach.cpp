class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // friends that cant communicate
        unordered_set<int> unknown;
        for(auto &f:friendships){
            int u=f[0]-1;
            int v=f[1]-1;
            unordered_set<int> lang_known_by_u(languages[u].begin(),languages[u].end());
            bool cantalk=false;
            for(auto &it:languages[v]){
                if(lang_known_by_u.find(it)!=lang_known_by_u.end()){
                    cantalk=true;
                    break;
                }
            }
            if(!cantalk){
                unknown.insert(u);
                unknown.insert(v);
            }
        }
        // number of languages known by ith friend
        vector<int> know(n+1,0);
        int most_known=0;
        for(int u:unknown){
            for(int l:languages[u]){
                know[l]++;
                most_known=max(most_known,know[l]);
            }
        }
        return unknown.size()-most_known;
    }
};