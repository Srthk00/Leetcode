class Solution {
public:
    int check(vector<int> nums,int mid){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=ceil(nums[i]/(double)mid);
        }
        return count;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1,high=*max_element(quantities.begin(),quantities.end());
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(quantities,mid)>n){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};