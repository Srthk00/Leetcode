#include <limits.h>
int myAtoi(char* s) {
    long long num=0;
    int i=0,sign=1;
    while(s[i]==' '){
        i++;
    }
    if(s[i]=='-'){
        sign=-1;
        i++;
    }
    else if(s[i]=='+'){
        i++;
    }
    while(s[i]>='0' && s[i]<='9'){
        num=num*10+(s[i]-'0');
        if(num*sign>INT_MAX){
            return INT_MAX;
        }
        if(num*sign<INT_MIN){
            return INT_MIN;
        }
        i++;
    }
    return (int)(num*sign);
}