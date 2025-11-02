class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(),nums.end());
        int i=0,j=nums[0];
        while(i<nums.size() && j<=nums[nums.size()-1]){
            if(nums[i]==j){
                i++;j++;
            }
            else{
                result.push_back(j);
                j++;
            }
        }
        return result;
    }
};