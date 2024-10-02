int mySqrt(int x) {
    if(x<2)
        return x;
    int start=2,end=x/2;
    while(start<=end){
        int mid=start+(end-start)/2;
        long long sq=(long long)mid*mid;
        if(sq==x)
            return mid;
        else if(sq<x)
            start=mid+1;
        else
            end=mid-1;
    }
    return end;
}