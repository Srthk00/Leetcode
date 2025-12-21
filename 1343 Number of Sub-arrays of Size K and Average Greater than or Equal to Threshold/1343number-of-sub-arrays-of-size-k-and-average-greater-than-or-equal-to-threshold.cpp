class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int result=0;
        int i=0,prev=0;
        double sum=0;
        while(i<k){
            sum+=arr[i++];
        }
        if(sum/k>=threshold){result++;}
        while(i<arr.size()){
            sum-=arr[prev++];
            sum+=arr[i++];
            if(sum/k>=threshold){result++;}
        }
        return result;
    }
};