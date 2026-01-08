class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        long long even=0,odd=0;
        for(int i:prefix){
            if(i%2==0){even++;}
            else{odd++;}
        }
        long long temp=odd+(even*odd);
        return temp%(int)(1e9+7);
    }
};