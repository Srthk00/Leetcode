#include <string.h>

char *defangIPaddr(const char *address) {
    int len=strlen(address);
    char *str=(char *)malloc((len+4*3+1)*sizeof(char));
    int j=0;
    for (int i=0;i<len;i++){
        if (address[i]!='.'){
            str[j++]=address[i];
        }
        else{
            str[j++]='[';
            str[j++]='.';
            str[j++]=']';
        }
    }
    str[j]='\0';
    return str;
}