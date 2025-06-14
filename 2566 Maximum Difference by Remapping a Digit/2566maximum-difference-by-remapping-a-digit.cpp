class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        string max=to_string(num);
        string min=to_string(num);
        char notnine;
        for(int i=0;i<str.size();i++){
            if(str[i]!='9'){
                notnine=str[i];
                break;
            }
        }
        for(int i=0;i<max.size();i++){
            if(max[i]==notnine){
                max[i]='9';
            }
        }
        char notzero;
        for(int i=0;i<str.size();i++){
            if(str[i]!='0'){
                notzero=str[i];
                break;
            }
        }
        for(int i=0;i<min.size();i++){
            if(min[i]==notzero){
                min[i]='0';
            }
        }
        return stoi(max)-stoi(min);
    }
};