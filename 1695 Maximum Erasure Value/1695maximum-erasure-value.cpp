class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int m=*max_element(nums.begin(),nums.end());
        vector<int> freq(m+1,0);
        int maxsum=0,currsum=0;
        int i=0,j=0;
        while(i<n && j<n){
            if(freq[nums[j]]==1){
                maxsum=max(maxsum,currsum);
                while(freq[nums[j]]>0){
                    currsum-=nums[i];
                    freq[nums[i]]--;
                    i++;
                }
            }
            else{
                currsum+=nums[j];
                freq[nums[j]]++;
                j++;
            }
        }
        maxsum=max(maxsum,currsum);
        return maxsum;
    }
};