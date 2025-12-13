class Solution {
public:
    bool check(string &str){
    if (str.empty()){
        return false;
    }
    for(char ch:str){
        if(!(isalnum(ch) || ch=='_')){
            return false;
        }
    }
    return true;
}
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int> map={
            {"electronics",1},
            {"grocery",2},
            {"pharmacy",3},
            {"restaurant",4}
        };
        vector<pair<int,string>> temp;
        for(int i=0;i<code.size();i++){
            if(isActive[i] && !code[i].empty() && map.count(businessLine[i]) && check(code[i])){
                temp.push_back({map[businessLine[i]],code[i]});
            }
        }
        sort(temp.begin(),temp.end(),[](pair<int,string> &a,pair<int,string> &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        vector<string> result;
        for(auto &str:temp){
            result.push_back(str.second);
        }
        return result;
    }
};