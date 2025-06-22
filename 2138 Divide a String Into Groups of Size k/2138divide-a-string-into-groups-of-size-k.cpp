class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int i=0;
        while(i+k<s.size()){
            string str=s.substr(i,k);
            result.push_back(str);
            i+=k;
        }
        string str=s.substr(i);
        int a=str.size();
        int b=k-a;
        for(int x=0;x<b;x++){
            str+=fill;
        }
        result.push_back(str);
        return result;
    }
};