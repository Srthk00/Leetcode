class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long N=n,M=m,K=k;
        if(n>k){
            return K*(N-K);
        }
        if(m>k){
            return K*(M-K);
        }
        return 0;
    }
};