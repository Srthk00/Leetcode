class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count=0;
        for(int i:nums){
            map[i]++;
        }
        for(auto &i:map){
            if(k==0){
                if(i.second>1)
                    count++;
            }
            else{
                int num=i.first;
                if(map.find(num+k)!=map.end())
                    count++;
            }
        }
        return count;
    }
};