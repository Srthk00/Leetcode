class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> result;
        result.push_back(nums[0]);
        int i=1;
        while(i<nums.size()){
            long long ele=nums[i];
            while(!result.empty() && result.back()==ele){
                ele*=2;
                result.pop_back();
            }
            result.push_back(ele);
            i++;
        }
        return result;
    }
};