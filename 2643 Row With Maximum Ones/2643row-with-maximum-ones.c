#include <stdlib.h>
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    *returnSize=2;
    int *arr=(int*)malloc(2*sizeof(int));
    arr[0]=0;
    arr[1]=0;
    for(int i=0;i<matSize;i++){
        int count=0;
        for(int j=0;j<matColSize[i];j++){
            if(mat[i][j]==1){
                count++;
            }
        }
        if(count>arr[1]){
            arr[0]=i;
            arr[1]=count;
        }
    }
    return arr;
}