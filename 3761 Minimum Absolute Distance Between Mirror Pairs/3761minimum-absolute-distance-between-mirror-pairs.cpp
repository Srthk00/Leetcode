class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int result=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                result=min(result,abs(i-mp[nums[i]]));
            }
            int n=0;
            int temp=nums[i];
            while(temp>0){
                n*=10;
                n+=(temp%10);
                temp/=10;
            }
            mp[n]=i;
        }
        return result==INT_MAX?-1:result;
    }
};