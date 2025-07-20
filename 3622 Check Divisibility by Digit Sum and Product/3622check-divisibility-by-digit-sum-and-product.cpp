class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long prod=1;
        int temp=n;
        while(temp>0){
            int d=temp%10;
            sum+=d;
            prod*=d;
            temp/=10;
        }
        long long div=sum+prod;
        return (n%div==0);
    }
};