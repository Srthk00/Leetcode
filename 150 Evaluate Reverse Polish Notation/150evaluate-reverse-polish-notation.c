#include <string.h>
#include <stdlib.h>
int evalRPN(char** tokens,int tokensSize) {
    int st[tokensSize],top=-1,temp;
    for(int i=0;i<tokensSize;i++){
        if(strcmp(tokens[i],"+")==0){
            temp=st[top--]+st[top];
            st[top]=temp;
        }
        else if(strcmp(tokens[i],"-")==0){
            temp=st[top--];
            st[top]=st[top]-temp;
        }
        else if(strcmp(tokens[i],"*")==0) {
            temp=st[top--]*st[top];
            st[top]=temp;
        }
        else if(strcmp(tokens[i],"/")==0){
            temp=st[top--];
            st[top]=st[top]/temp;
        }
        else{
            st[++top]=atoi(tokens[i]);
        }
    }
    return st[top];
}