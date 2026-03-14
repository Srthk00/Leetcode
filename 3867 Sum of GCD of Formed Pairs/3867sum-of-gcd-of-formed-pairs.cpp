class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGCD(n),maxtill(n,0);
        maxtill[0]=nums[0];
        for(int i=1;i<n;i++){
            maxtill[i]=max(maxtill[i-1],nums[i]);
        }
        for(int i=0;i<n;i++){
            prefixGCD[i]=gcd(maxtill[i],nums[i]);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        long long result=0;
        int low=0,high=n-1;
        while(low<high){
            result+=gcd(prefixGCD[low],prefixGCD[high]);
            low++;high--;
        }
        return result;
    }
};