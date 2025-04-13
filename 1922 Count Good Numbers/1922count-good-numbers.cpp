class Solution {
public:
    const int mod=1e9+7;
    long long expo(long long a,long long b){
        if(b==0)
            return 1;
        long long halve=expo(a,b/2);
        if(b%2==0)
            return (halve*halve)%mod;
        else
            return (a*halve*halve)%mod;
    }

    int countGoodNumbers(long long n) {
        long even=(n+1)/2;;
        long odd=n/2;
        return expo(5,even)*expo(4,odd)%mod;
    }
};