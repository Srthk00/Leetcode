#include <string.h>
char findTheDifference(char* s, char* t) {
    int arr[256]={0};
    for(int i=0;i<strlen(s);i++){
        arr[s[i]]++;
    }
    for(int i=0;i<strlen(t);i++){
        arr[t[i]]--;
    }
    for(int i=0;i<256;i++){
        if(arr[i]<0)
            return i;
    }
    return '\0';
}