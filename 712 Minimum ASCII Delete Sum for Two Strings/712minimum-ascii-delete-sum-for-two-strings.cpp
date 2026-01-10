class Solution {
public:
    vector<vector<int>> dp;

    int func(string &s1,string &s2,int i,int j){
        if(i>=s1.size()){
            int sum=0;
            for(int x=j;x<s2.size();x++){
                sum+=s2[x];
            }
            return sum;
        }
        if(j>=s2.size()){
            int sum=0;
            for(int x=i;x<s1.size();x++){
                sum+=s1[x];
            }
            return sum;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        if(s1[i]==s2[j]){return dp[i][j]=func(s1,s2,i+1,j+1);}
        else{
            return dp[i][j]=min(s1[i]+func(s1,s2,i+1,j),s2[j]+func(s1,s2,i,j+1));
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        dp.assign(s1.size()+1,vector<int>(s2.size()+1,-1));
        return func(s1,s2,0,0);
    }
};