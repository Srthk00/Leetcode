class Solution {
public:
    vector<string> strs;

    void generate(int n,string str){
        if(str.size()==n){
            strs.push_back(str);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(str.size()==0 || ch!=str.back()){
                generate(n,str+ch);
            }
        }
    }

    string getHappyString(int n, int k) {
        string str="";
        generate(n,str);
        if(strs.size()<k){return "";}
        return strs[k-1];
    }
};