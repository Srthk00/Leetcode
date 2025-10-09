class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long> nums(n,0);
        for(int i=0;i<m;i++){
            nums[0]+=mana[i]*skill[0];
            for(int j=1;j<n;j++){
                nums[j]=max(nums[j],nums[j-1])+1LL*skill[j]*mana[i];
            }
            for(int k=n-1;k>0;k--){
                nums[k-1]=nums[k]-1LL*skill[k]*mana[i];
            }
        }
        return nums[n-1];
    }
};