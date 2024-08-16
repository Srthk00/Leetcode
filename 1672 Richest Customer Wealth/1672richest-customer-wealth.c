int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int count=0,max=0;
    for(int i=0;i<accountsSize;i++){
        for(int j=0;j<accountsColSize[i];j++){
            count+=accounts[i][j];
        }
        if(count>max)
            max=count;
        count=0;
    }
    return max;
}