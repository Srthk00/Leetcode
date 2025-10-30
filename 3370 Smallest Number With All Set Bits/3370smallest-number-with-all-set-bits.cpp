class Solution {
public:
    int smallestNumber(int n) {
        for(int i=n;i<=1024;i++){
            if((i&(i+1))==0){return i;}
        }
        return -1;
    }
};