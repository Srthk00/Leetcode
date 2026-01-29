class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26,vector<long long>(26,1e18));
        for(int i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a']=min(dist[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }
        for(int i=0;i<26;i++){dist[i][i]=0;}
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]!=1e18 && dist[k][j]!=1e18){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        long long result=0;
        for(int i=0;i<source.size();i++){
            int s=source[i]-'a';
            int t=target[i]-'a';
            if(dist[s][t]==1e18){return -1;}
            result+=dist[s][t];
        }
        return result;
    }
};