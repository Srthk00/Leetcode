class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> map;
        for(int i:nums){map[i]=true;}
        for(int i:nums){
            if(map.count(i-1)){map[i]=false;}
        }
        int result=0;
        for(auto [n,e]:map){
            if(e){
                int curr=1,temp=1;
                while(map.count(n+temp)){
                    curr++;temp++;
                }
                result=max(result,curr);
            }
        }
        return result;
    }
};