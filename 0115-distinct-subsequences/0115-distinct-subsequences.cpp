class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i,int j,string &s,string &t){
        if(j==t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int match=0,skip=0;
        if(s[i]==t[j]){
            match=solve(i+1,j+1,s,t);
            skip=solve(i+1,j,s,t);
            return dp[i][j]=match+skip;
        }
        return dp[i][j]=solve(i+1,j,s,t);
        
    }

    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        return solve(0,0,s,t);
    }
};