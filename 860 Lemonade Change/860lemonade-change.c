bool lemonadeChange(int* bills, int billsSize) {
    int no_of_5=0,no_of_10=0,flag=1;
    for(int i=0;i<billsSize;i++){
        if(bills[i]==5)
            no_of_5++;
        else if(bills[i]==10){
            if(no_of_5!=0){
                no_of_5--;
                no_of_10++;
            }
            else
                return false;
        }
        else{
            if(no_of_10!=0 && no_of_5!=0){
                no_of_5--;
                no_of_10--;
            }
            else if(no_of_5>=3){
                no_of_5-=3;
            }
            else
                return false;
        }
    }
    return true;
}