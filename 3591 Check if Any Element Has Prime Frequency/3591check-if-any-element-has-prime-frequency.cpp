class Solution {
public:
    bool isprime(int num){
        for(int i=2;i<=num/2;i++){
            if(num%i==0){return false;}
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(*max_element(nums.begin(),nums.end())+1,0);
        for(int i:nums){
            freq[i]++;
        }
        for(int i:freq){
            if(i>1){
                if(isprime(i)){return true;}
            }
        }
        return false;
    }
};