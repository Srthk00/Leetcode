class Solution {
public:
    int maxDiff(int num) {
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

        char findmin;
        if(str[0]=='1'){
            for(int i=1;i<str.size();i++){
                if(str[i]!='1' && str[i]!='0'){
                    findmin=str[i];
                    break;
                }
            }
            for(int i=0;i<min.size();i++){
                if(min[i]==findmin){
                    min[i]='0';
                }
            }
        }
        else{
            findmin=str[0];
            for(int i=0;i<min.size();i++){
                if(min[i]==findmin){
                    min[i]='1';
                }
            }
        }

        return stoi(max)-stoi(min);
    }
};