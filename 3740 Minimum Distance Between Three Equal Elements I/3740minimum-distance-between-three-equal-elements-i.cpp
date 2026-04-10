class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int result = INT_MAX;
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(i!=j && j!=k && i!=k){
                        if(nums[i]==nums[j] && nums[j]==nums[k]){
                            flag=true;
                            result=min(result,abs(i-j)+abs(j-k)+abs(k-i));
                        }
                    }
                }   
            }
        }
        return flag?result:-1;
    }
};