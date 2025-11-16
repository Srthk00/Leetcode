class Solution {
public:
    int numSub(string s) {
        long long result=0;
        int j=0;
        while(j<s.size()){
            while(s[j]=='0'){j++;}
            long long n=0;
            while(s[j]=='1'){
                j++;n++;
            }
            result=(result+(n*(n+1)/2))%1000000007;
        }
        return (int)result;
    }
};