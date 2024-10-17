long long getDescentPeriods(int* prices, int pricesSize) {
    long long count=1;
    long long temp=1;
    for (int i=1;i<pricesSize;i++){
        if(prices[i]==prices[i-1]-1){
            temp++;
        }
        else{
            temp=1;
        }
        count+=temp;
    }
    return count;
}