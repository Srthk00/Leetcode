class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        for(int i:nums){
            if(i<pivot)
                result.push_back(i);
        }
        for(int i:nums){
            if(i==pivot)
                result.push_back(i);
        }
        for(int i:nums){
            if(i>pivot)
                result.push_back(i);
        }
        return result;
    }
};