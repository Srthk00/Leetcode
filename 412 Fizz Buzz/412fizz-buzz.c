#include <string.h>
char** fizzBuzz(int n, int* returnSize) {
    char **arr=(char**)malloc(n*sizeof(char*));
    for(int i=1;i<=n;i++){
        if(i%3==0 && i%5==0){
            arr[i-1]=(char*)malloc(9*sizeof(char));
            strcpy(arr[i-1],"FizzBuzz");
        }
        else if(i%3==0){
            arr[i-1]=(char*)malloc(5*sizeof(char));
            strcpy(arr[i-1],"Fizz");
        }
        else if(i%5==0){
            arr[i-1]=(char*)malloc(5*sizeof(char));
            strcpy(arr[i-1],"Buzz");
        }
        else{
            arr[i-1]=(char*)malloc(5*sizeof(char));
            sprintf(arr[i-1],"%d",i);
        }
    }
    *returnSize=n;
    return arr;
}