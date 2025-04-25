class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int temp=sum-k;
            if(map.find(temp)!=map.end()){
                count+=map[temp];
            }
            map[sum]++;
        }
        return count;
    }
};