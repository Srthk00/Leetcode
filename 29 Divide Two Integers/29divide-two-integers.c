int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor==-1) {
        return INT_MAX;
    }
    if(dividend==INT_MIN && divisor==1){
        return INT_MIN;
    }
    if(dividend==INT_MAX && divisor==1){
        return INT_MAX;
    }
    if(dividend==INT_MAX && divisor==-1){
        return INT_MIN+1;
    }
    int sign=(dividend<0)^(divisor<0);
    long long num=labs(dividend);
    long long denum=labs(divisor);
    int q=0;
    while(num>=denum) {
        num-=denum;
        q++;
    }
    if(sign)
        return -q;
    else
        return q;
}