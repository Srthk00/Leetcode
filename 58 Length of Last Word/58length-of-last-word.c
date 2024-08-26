#include <string.h>
int lengthOfLastWord(char* s) {
    int count=0,len=strlen(s),i=len-1;
    while(s[i]==' '){
        i--;
    }
    for(i;i>=0 && s[i]!=' ';i--){
        count++;
    }
    return count;
}