class Solution {
public:
    int findLucky(vector<int>& arr) {
        int m=*max_element(arr.begin(),arr.end());
        vector<int> freq(m+1,0);
        for(int i:arr){
            freq[i]++;
        }
        for(int i=m;i>0;i--){
            if(freq[i]==i){
                return i;
            }
        }
        return -1;
    }
};