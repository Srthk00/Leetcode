class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result=0;
        for(string str:patterns){
            if(word.find(str)!=string::npos){
                result++;
            }
        }
        return result;
    }
};