class Solution {
public:
    vector<vector<int>> dp;

    int check(int i,int j,string &s){
        if(i>=j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]!=s[j]){
            return dp[i][j]=0;
        }
        return dp[i][j]=check(i+1,j-1,s);
    }

    string longestPalindrome(string s) {
        int n=s.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        int l=1;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    if(j-i+1>l){
                        l=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,l);
    }
};