class Solution {
public:
    vector<long long> dp;
    vector<int> nums;
    unordered_map<int,int> mp;

    long long func(int i){
        if(i>=nums.size()){return 0;}
        if(dp[i]!=-1){return dp[i];}
        long long donttake=func(i+1);
        long long take=1LL*nums[i]*mp[nums[i]];
        int j=i+1;
        while(j<nums.size() && nums[i]-nums[j]<=2){j++;}
        take+=func(j);
        return dp[i]=max(take,donttake);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for(int i:power){
            mp[i]++;
        }
        set<int> st(power.begin(),power.end());
        nums=vector<int>(st.begin(),st.end());
        sort(nums.rbegin(),nums.rend());
        dp=vector<long long>(nums.size(),-1);
        return func(0);
    }
};