class Solution {
public:
    int MOD=1e9+7;
    
    long long power(int b,int p){
        if(p==0){
            return 1;
        }
        long long half=power(b,p/2);
        long long res=(half*half)%MOD;
        if(p%2){
            return (1LL*b*res)%MOD;
        }
        else{
            return res;
        }
    }
    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n=nums1.size();
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++){
            nums[i]={nums1[i],nums0[i]};
        }
        sort(nums.begin(),nums.end(),[](auto &a,auto &b){
            int a1 = a.first;
            int a2 = a.second;
            int a3 = b.first;
            int a4 = b.second;
            string s1(a1,'1');
            string s2(a3,'1');
            string s3(a2,'0');
            string s4(a4,'0');
            s1 += s3;
            s2 += s4;
            return s1 + s2 > s2 + s1;
        });
        int result=0;
        for(int i=0;i<n;i++){
            int one=nums[i].first;
            int zero=nums[i].second;
            int powerr=power(2,one);
            result=(1LL*result*powerr)%MOD;
            result=(1LL*result+powerr-1+MOD)%MOD;
            int po=power(2,zero);
            result=(1LL*result*po)%MOD;
        }
        return result;
    }
};