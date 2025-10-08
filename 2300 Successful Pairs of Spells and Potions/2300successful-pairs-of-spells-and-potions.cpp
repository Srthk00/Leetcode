class Solution {
public:
    int bs(vector<int> &nums,long long target){
        int low=0,high=nums.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if((long long)nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> result;
        for(int i:spells){
            long long comp=(success+i-1)/i;
            int idx=bs(potions,comp);
            result.push_back(m-idx);
        }
        return result;
    }
};