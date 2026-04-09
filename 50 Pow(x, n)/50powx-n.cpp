class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n==INT_MIN){
            if(x==1 || x==-1){
                return 1;
            }
            return 0;
        }
        if(n<0){
            return 1/myPow(x,-n);
        }
        double half=myPow(x,n/2);
        if(n%2){
            return x*half*half;
        }
        else{
            return half*half;
        }
    }
};