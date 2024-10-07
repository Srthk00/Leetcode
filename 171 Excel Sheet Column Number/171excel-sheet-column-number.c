#include <string.h>
int titleToNumber(char* columnTitle) {
    int SIZE=strlen(columnTitle);
    int result=0;
    for(int i=0;i<SIZE;i++){
        result=result*26+(columnTitle[i]-'A'+1);
    }
    return result;
}