class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=1;
        int n=nums.size();
        int x=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[x]>k){
                count++;
                x=i+1;
            }
        }
        return count;
    }
};