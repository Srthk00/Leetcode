class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        vector<int> result;
        int last=nums[0];
        int i=1;
        result.push_back(last);
        while(i<nums.size() && k>0){
            if(result.size()==k){break;}
            if(nums[i]!=last){
                result.push_back(nums[i]);
                last=nums[i];
            }
            i++;
        }
        return result;
    }
};