int shipWithinDays(int* weights, int weightsSize, int days) {
    int start=0,end=0;
    for(int i=0;i<weightsSize;i++){
        end+=weights[i];
        if(start<weights[i])
            start=weights[i];
    }
    while(start<=end){
        int diff=(start+end)/2;
        int days_taken=fun(weights,weightsSize,diff);
        if(days_taken<=days)
            end=diff-1;
        else
            start=diff+1;
    }
    return start;
}
int fun(int* weights,int weightsSize,int capacity){
    int days_taken=1,load=0;
    for(int i=0;i<weightsSize;i++){
        if(load+weights[i]>capacity){
            days_taken++;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days_taken;
}