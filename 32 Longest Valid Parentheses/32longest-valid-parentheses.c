#include <string.h>
int longestValidParentheses(char* s){
    int size=strlen(s),top=0,len=0,max=0;
    int *stack=(int *)malloc((size+1)*sizeof(int));
    stack[top]=-1;
    for(int i=0;i<size;i++){
        if(s[i]=='('){
            stack[++top]=i;
        }
        else{
            top--;
            if(top==-1)
                stack[++top]=i;
            else{
                len=i-stack[top];
                if(len>max)
                    max=len;
            }
        }
    }
    return max;
}