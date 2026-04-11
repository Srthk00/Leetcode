class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<bool> primes(110000,true);
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=110000;i++){
            if(primes[i]){
                for(int j=i*i;j<=110000;j+=i){
                    primes[j]=false;
                }
            }
        }
        vector<int> next(primes.size()+1,-1);
        int temp=-1;
        for(int i=109999;i>=0;i--){
            if(primes[i]){
                temp=i;
            }
            next[i]=temp;
        }
        vector<int> nextnon(primes.size()+1,-1);
        int t=-1;
        for(int i=109999;i>=0;i--){
            if(!primes[i]){
                t=i;
            }
            nextnon[i]=t;
        }
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0 && !primes[nums[i]]){
                result+=abs(nums[i]-next[nums[i]]);
            }
            else if(i%2==1 && primes[nums[i]]){
                result+=abs(nums[i]-nextnon[nums[i]]);
            }
        }
        return result;
    }
};