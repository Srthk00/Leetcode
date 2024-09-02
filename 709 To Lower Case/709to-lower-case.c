#include <ctype.h>
char* toLowerCase(char* s) {
    int size=strlen(s),i;
    char *str=(char *)malloc((size+1)*sizeof(char));
    for(i=0;i<size;i++){
        str[i]=tolower(s[i]);
    }
    str[i]='\0';
    return str;
}