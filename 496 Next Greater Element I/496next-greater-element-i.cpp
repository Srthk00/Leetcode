class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            int j=0;
            while(nums2[j]!=nums1[i]){
                j++;
            }
            while(j<nums2.size()){
                if(nums2[j]>nums1[i]){
                    result.push_back(nums2[j]);
                    break;
                }
                j++;
            }
            if(j==nums2.size()){
                result.push_back(-1);
            }
        }
        return result;
    }
};