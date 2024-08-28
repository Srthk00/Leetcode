#include <string.h>
bool isAnagram(char* s, char* t) {
    int lens=strlen(s),lent=strlen(t);
    int arr[256]={0};
    for(int i=0;i<lens;i++){
        arr[s[i]]++;
    }
    for(int i=0;i<lent;i++){
        arr[t[i]]--;
    }
    for(int i=0;i<256;i++){
        if(arr[i]!=0)
            return false;
    }
    return true;
}