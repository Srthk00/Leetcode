class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size=nums1.size()+nums2.size();
        vector<int> nums3;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            nums3.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            nums3.push_back(nums2[j]);
            j++;
        }
        int med=nums3.size()/2;
        double result;
        if(nums3.size()%2==1){
            result=nums3[med];
            return result;
        }
        else{
            result=(nums3[med-1]+nums3[med])/2.00;
            return result;
        }
    }
};