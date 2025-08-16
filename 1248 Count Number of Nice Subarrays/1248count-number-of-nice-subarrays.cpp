class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%2;
        }
        int result=0,sum=0;
        unordered_map<int,int> map;
        for(int i:nums){
            sum+=i;
            if(sum==k){
                result++;
            }
            int comp=sum-k;
            if(map.find(comp)!=map.end()){
                result+=map[comp];
            }
            map[sum]++;
        }
        return result;
    }
};