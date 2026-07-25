class Solution {
public:
    int mySqrt(int x) {
        if(x<2){
            return x;
        }
        int low=2,high=x/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long sq=(long long)mid*mid;
            if(sq==x){
                return mid;
            }
            else if(sq<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};