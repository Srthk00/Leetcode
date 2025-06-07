class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> map(26);
        vector<char> str(s.begin(),s.end());
        for(int i=0;i<str.size();i++){
            if(str[i]=='*'){
                str[i]='$';
                for(int j=0;j<26;j++){
                    if(!map[j].empty()){
                        str[map[j].back()]='$';
                        map[j].pop_back();
                        break;
                    }
                }
            }
            else{
                map[str[i]-'a'].push_back(i);
            }
        }
        string result="";
        for(char ch:str){
            if(ch!='$'){
                result+=ch;
            }
        }
        return result;
    }
};