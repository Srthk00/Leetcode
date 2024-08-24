bool isPalindrome(int x) {
    if(x<0)
        return false;
    long int copy=x,check=0,temp;
    while(copy>0){
        temp=copy%10;
        check=check*10+temp;
        copy/=10;
    }
    if(check==x)
        return true;
    else
        return false;
}