class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3){return 0;}
        int j=0;
        int result=0;
        while(j<n){
            int curr=0;
            if(j<n-1 && arr[j]<arr[j+1]){
                while(j<n-1 && arr[j]<arr[j+1]){
                    j++;curr++;
                }
                if(j<n-1 && arr[j]>arr[j+1]){
                    while(j<n-1 && arr[j]>arr[j+1]){
                        j++;curr++;
                    }
                    result=max(result,curr+1);
                }
            }
            else{
                j++;
            }
        }
        return result;
    }
};