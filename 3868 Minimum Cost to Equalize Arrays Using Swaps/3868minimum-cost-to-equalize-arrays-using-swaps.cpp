class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp,mp1,mp2;
        for(int i:nums1){mp[i]++;mp1[i]++;}
        for(int i:nums2){mp[i]++;mp2[i]++;}
        for(auto &it:mp){
            if(it.second%2==1){
                return -1;
            }
        }
        int result=0;
        for(auto &[e,f]:mp){
            int curr=mp1[e];
            int temp=f/2;
            // if nums1 have more than f/2, move excess to other array, and swap them with elements have freq < f/2
            if(curr>temp){result+=curr-temp;}
        }
        return result;
    }
};