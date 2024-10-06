/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
#include<stdbool.h>
bool func(int num){
    int temp=num;
    while(num>0){
        int t=num%10;
        if(t==0 || temp%t!=0){
            return false;
        }
        num/= 10;
    }
    return true;
}
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* arr =(int*)malloc((right-left+1)*sizeof(int));
    *returnSize=0;
    for(int i=left;i<=right;i++){
        if(func(i)){
            arr[*returnSize]=i;
            (*returnSize)++;
        }
    }
    arr=(int*)realloc(arr,(*returnSize)*sizeof(int));
    return arr;
}