#include <string.h>
long long minimumSteps(char* s) {
    long long steps=0;
    int onesCount=0;
    int length=strlen(s);
    for(int i=0;i<length;i++){
        if(s[i]=='1'){
            onesCount++;
        }
        else{
            steps+=onesCount;
        }
    }
    return steps;
}