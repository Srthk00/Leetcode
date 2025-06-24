class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                int left=i-k<0?0:i-k;
                int right=i+k>=nums.size()?nums.size()-1:i+k;
                for(int j=left;j<=right;j++){
                    temp.insert(j);
                }
            }
        }
        vector<int> result(temp.begin(),temp.end());
        sort(result.begin(),result.end());
        return result;
    }
};