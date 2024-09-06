bool detectCapitalUse(char* word) {
    bool flag=isupper(word[0]),lower=true,upper=true;
    for(int i=1;word[i]!='\0';i++){
        if(isupper(word[i])){
                lower=false;
        }
        else{
            upper=false;
        }
    }
    return (flag && upper) || (!flag && lower) || (flag && lower) ;
}