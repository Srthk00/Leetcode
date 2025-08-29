class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddn=(n+1)/2;
        long long evenn=n/2;
        long long oddm=(m+1)/2;
        long long evenm=m/2;
        return oddn*evenm + oddm*evenn;
    }
};