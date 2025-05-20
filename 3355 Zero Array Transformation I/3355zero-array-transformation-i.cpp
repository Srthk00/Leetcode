class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n,0);
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];   
            int b=queries[i][1];
            if(a<n){diff[a]+=1;}
            if(b+1<n){diff[b+1]-=1;}
        }
        vector<int> prefix(n);
        prefix[0]=diff[0];
        for(int i=1;i<n;i++){
            prefix[i]=diff[i]+prefix[i-1];
        }
        for(int i=0;i<n;i++){
            if(prefix[i]<nums[i]){return false;}
        }
        return true;
    }
};