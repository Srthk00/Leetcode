class Solution {
public:
    bool isPowerOfFour(int n) {
        long long check=1;
        while(check<=INT_MAX){
            if(check==n){return true;}
            check*=4;
        }
        return false;
    }
};