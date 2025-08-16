class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result=0,sum=0;
        unordered_map<int,int> map;
        for(int i:nums){
            sum+=i;
            if(sum==goal){
                result++;
            }
            int comp=sum-goal;
            if(map.find(comp)!=map.end()){
                result+=map[comp];
            }
            map[sum]++;
        }
        return result;
    }
};