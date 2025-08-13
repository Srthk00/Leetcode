class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1){return false;}
        long long check=1;
        while(check<=INT_MAX){
            if(n==check){return true;}
            check*=3;
        }
        return false;
    }
};