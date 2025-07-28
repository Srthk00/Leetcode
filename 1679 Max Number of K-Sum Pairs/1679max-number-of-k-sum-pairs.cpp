class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> map;
        int count=0;
        for(int i:nums){
            int comp=k-i;
            if(map[comp]>0){
                count++;
                map[comp]--;
            }
            else{
                map[i]++;
            }
        }
        return count;
    }
};