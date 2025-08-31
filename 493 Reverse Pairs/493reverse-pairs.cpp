class Solution {
private:
    int result=0;
public:
    void calculate(vector<int> &nums,int low,int mid,int high){
        int x=low,y=mid+1;
        while(x<=mid){
            while(y<=high && (long long)nums[x]>2LL*nums[y]){
                y++;
            }
            x++;
            result+=y-(mid+1);
        }
        vector<int> temp(high-low+1);
        int idx=0;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                temp[idx++]=nums[i++];
            }
            else{
                temp[idx++]=nums[j++];
            }
        }
        while(i<=mid){
            temp[idx++]=nums[i++];
        }
        while(j<=high){
            temp[idx++]=nums[j++];
        }
        idx=0;
        for(int a=low;a<=high;a++){
            nums[a]=temp[idx++];
        }
    }

    void divide(vector<int> &nums,int low,int high){
        if(low<high){
            int mid=low+(high-low)/2;
            divide(nums,low,mid);
            divide(nums,mid+1,high);
            calculate(nums,low,mid,high);
        }
    }

    int reversePairs(vector<int>& nums) {
        divide(nums,0,nums.size()-1);
        return result;
    }
};