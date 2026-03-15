class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000){return 0;}
        long long result=0;
        map<long,int> mp;
        mp[1000LL]=1;mp[1000000LL]=2;mp[1000000000LL]=3;mp[1000000000000LL]=4;mp[1000000000000000LL]=5;
        for(auto &[s,c]:mp){
            if(s>n){break;}
            long long till=min(n,s*1000LL-1);
            result+=(till-s+1)*c;
        }
        return result;
    }
};