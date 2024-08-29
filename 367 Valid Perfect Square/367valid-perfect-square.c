bool isPerfectSquare(int num) {
    int start=1,end=num;
    if(num==0 || num==1)
        return true;
    while(start<=end){
        int diff=start+(end-start)/2;
        long long sq=(long long)diff*diff;
        if(sq==num)
            return true;
        else if(sq>num)
            end=diff-1;
        else 
            start=diff+1;
    }
    return false;
}