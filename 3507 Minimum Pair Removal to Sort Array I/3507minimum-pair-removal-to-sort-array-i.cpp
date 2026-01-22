class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int result=0;
        while(nums.size()>1){
            bool flag=true;
            for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1]){flag=false;break;}
            }
            if(flag){break;}
            result++;
            int minsum=nums[0]+nums[1],idx=0;
            for(int i=1;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<minsum){
                    minsum=nums[i]+nums[i+1];
                    idx=i;
                }
            }
            vector<int> temp;
            for(int i=0;i<nums.size();i++){
                if(i==idx){
                    temp.push_back(nums[i]+nums[i+1]);i++;
                }
                else{temp.push_back(nums[i]);}
            }
            nums=temp;
        }
        return result;
    }
};