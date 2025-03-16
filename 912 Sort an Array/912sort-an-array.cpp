class Solution {
public:
    void merge(vector<int>& arr,int low,int mid,int high){
        vector<int> temp;
        int i=0;
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);    
            }
            else{   
                temp.push_back(arr[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);    
        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }

    void divide(vector<int>& arr,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            divide(arr,low,mid);
            divide(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        divide(nums,0,nums.size()-1);
        return nums;
    }
};