class Solution {
public:
    string reformat(string s) {
        vector<char> num;
        vector<char> dig;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                num.push_back(s[i]);
            }
            else{
                dig.push_back(s[i]);
            }
        }
        int n=num.size();
        int m=dig.size();
        if(n-m>1 || n-m<-1){
            return  "";
        }
        string str="";
        int i=0,j=0;
        if(num.size()>dig.size()){
            str+=num[i++];
        }
        while(i<num.size() && j<dig.size()){
            str+=dig[j++];
            str+=num[i++];
        }
        if(i<num.size()){
            str+=num[i];
        }
        if(j<dig.size()){
            str+=dig[j];
        }
        return str;
    }
};