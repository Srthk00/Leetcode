class Solution {
public:
    int valid(vector<int> nums,int max,int k){
        int SIZE=1;
        int sum=0;
        for(int i:nums){
            if(sum+i>max){
                SIZE++;
                sum=i;
                if(SIZE>k){
                    return 0;
                }
            }
            else{
                sum+=i;
            }
        }
        return 1;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i:nums){
            high+=i;
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(valid(nums,mid,k)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};