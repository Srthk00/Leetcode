class Solution {
public:
    vector<bool> soe(int n){
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int p=2;p*p<=n;p++){
            if(prime[p]==true){
                for(int m=p*p;m<=n;m+=p){
                    prime[m]=false;
                }
            }
        }
        return prime;
    }
    
    long long splitArray(vector<int>& nums) {
        int m=nums.size();
        vector<bool> primes=soe(m);
        long long primesum=0,othersum=0;
        for(int i=0;i<m;i++){
            if(primes[i]){
                primesum+=nums[i];
            }
            else{
                othersum+=nums[i];
            }
        }
        return abs(primesum-othersum);
    }
};