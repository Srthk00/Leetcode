class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int min_ele=*min_element(nums.begin(),nums.end());
        // 1-> even 0->odd
        int reqPar=(min_ele%2==0)?1:0;
        sort(nums.begin(),nums.end());
        vector<int> even(n,0),odd(n,0);
        if(nums[0]%2==0){
            even[0]++;
        }
        else{
            odd[0]++;
        }
        for(int i=1;i<n;i++){
            if(nums[i]%2==0){
            even[i]++;
            }
            else{
                odd[i]++;
            }
            even[i]+=even[i-1];
            odd[i]+=odd[i-1];
        }
        for(int i=1;i<n;i++){
            int par=(nums[i]%2==0)?1:0;
            if(par==reqPar){continue;}
            if(odd[i-1]==0){
                return false;
            }
        }
        return true;
    }
};