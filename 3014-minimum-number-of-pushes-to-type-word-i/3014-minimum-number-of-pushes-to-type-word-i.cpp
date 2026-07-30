class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int result=0;
        int t=1;
        while(n>8){
            result+=(8*t);
            n-=8;
            t++;
        }
        result+=n*t;
        return result;
    }
};