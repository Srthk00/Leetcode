class Solution {
public:
    int mirrorDistance(int n) {
        int temp=0,n_=n;
        while(n>0){
            temp*=10;
            temp+=(n%10);
            n/=10;
        }
        return abs(n_-temp);
    }
};