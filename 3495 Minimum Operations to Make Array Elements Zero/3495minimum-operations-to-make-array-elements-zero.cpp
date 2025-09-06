class Solution {
public:
    long long func(long long l,long long r){
        long long L=1;
        long long steps=0;
        long long x=1;
        while(L<=r){
            long long R=4*L-1;
            long long i=max(L,l);
            long long j=min(R,r);
            if(i<=j){
                steps+=(j-i+1)*x;
            }
            x++;
            L=4*L;
        }
        return steps;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long result=0;
        for(auto &it:queries){
            long long l=it[0];
            long long r=it[1];
            long long steps=func(l,r);
            result+=(steps+1)/2;
        }
        return result;
    }
};