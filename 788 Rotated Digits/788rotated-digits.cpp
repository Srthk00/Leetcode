class Solution {
public:
    int rotatedDigits(int n) {
        int result=0;
        for(int i=1;i<=n;i++){
            string str=to_string(i);
            bool flag=true;
            for(int j=0;j<str.size();j++){
                if(str[j]=='3' || str[j]=='4' || str[j]=='7'){
                    flag=false;
                    break;
                }
                if(str[j] == '2'){str[j]='5';}
                else if(str[j] == '5'){str[j]='2';}
                else if(str[j] == '6'){str[j]='9';}
                else if(str[j] == '9'){str[j] = '6';}
            }
            if(flag && i!=stoi(str)){
                result++;
            }
        }
        return result;
    }
};