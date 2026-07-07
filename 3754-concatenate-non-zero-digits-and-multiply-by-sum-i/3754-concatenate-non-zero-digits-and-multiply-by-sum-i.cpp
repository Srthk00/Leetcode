class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        int count=0;
        while(n>0){
            int digit=n%10;
            if(digit!=0){
                sum+=digit;
                digit*=(int)pow(10,count++);
                digit+=x;
                x=digit;
            }
            n/=10;
        }
        return x*sum;
    }
};