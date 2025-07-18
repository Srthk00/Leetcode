class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int len=1;
        int sp=0;
        for(int l=1;l<=s.size();l++){
            for(int i=0;l+i-1<s.size();i++){
                int j=l+i-1;
                if(i==j){dp[i][j]=true;}
                else if(i+1==j){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=((s[i]==s[j]) && dp[i+1][j-1]);
                }
                if(dp[i][j]){
                    if(j-i+1>len){
                        len=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,len);
    }
};