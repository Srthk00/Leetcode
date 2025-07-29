class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result;
        vector<int> r1,r2;
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        unordered_map<int,int> map1,map2;
        for(int i:s1){
            map1[i]++;
        }
        for(int i:s2){
            map2[i]++;
        }
        for(int i:s1){
            if(map2.find(i)==map2.end()){
                r1.push_back(i);
            }
        }
        for(int i:s2){
            if(map1.find(i)==map1.end()){
                r2.push_back(i);
            }
        }
        result.push_back(r1);
        result.push_back(r2);
        return result;
    }
};