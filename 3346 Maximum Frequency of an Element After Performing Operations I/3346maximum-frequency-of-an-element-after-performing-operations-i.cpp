class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int m=*max_element(nums.begin(),nums.end())+k;
        vector<int> freq(m+1,0);
        for(int i:nums){
            freq[i]++;
        }
        for(int i=1;i<freq.size();i++){
            freq[i]=freq[i]+freq[i-1];
        }
        int result=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0){continue;}
            int l=max(0,i-k);
            int r=min(m,i+k);
            int total=freq[r]-(l>0?freq[l-1]:0);
            int tcount=freq[i]-(i>0?freq[i-1]:0);
            int ttemp=total-tcount;
            int newfreq=tcount+min(ttemp,numOperations);
            result=max(result,newfreq);
        }
        return result;
    }
};