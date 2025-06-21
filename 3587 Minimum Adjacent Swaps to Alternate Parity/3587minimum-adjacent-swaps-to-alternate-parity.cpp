class Solution {
public:
    int func(vector<int> &arr){
        int swaps=0;
        int j=0;
        for(int i=0;i<arr.size();i++){
            swaps+=abs(arr[i]-j);
            j+=2;
        }
        return swaps;
    }
    
    int minSwaps(vector<int>& nums) {
        vector<int> even,odd;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even.push_back(i);
            }
            else{
                odd.push_back(i);
            }
        }
        int e=even.size();
        int o=odd.size();
        if(abs(e-o)>1){return -1;}
        int result=INT_MAX;
        if(e>=o){
            result=min(result,func(even));
        }
        if(o>=e){
            result=min(result,func(odd));
        }
        return result;
    }
};