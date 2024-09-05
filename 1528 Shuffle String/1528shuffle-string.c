#include <string.h>
char* restoreString(char* s, int* indices, int indicesSize) {
    char *str=(char*)malloc((strlen(s)+1)*sizeof(char));
    for(int i=0;i<strlen(s);i++){
        str[indices[i]]=s[i];
    }
    str[indicesSize]='\0';
    return str;
}