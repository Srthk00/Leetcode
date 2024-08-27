int strStr(char* haystack, char* needle) {
    int i=0,j=0;
    while(haystack[i]!='\0'){
        if(needle[j]==haystack[i]){
            j++;
            if(needle[j]=='\0')
                return i-j+1;
        }
        else{
            i-=j;
            j=0;
        }
        i++;
    }
    return -1;
}