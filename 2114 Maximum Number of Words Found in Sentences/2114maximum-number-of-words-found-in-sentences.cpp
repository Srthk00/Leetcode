class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int result=0;
        for(string str:sentences){
            int count=0;
            for(char ch:str){
                if(ch==' '){count++;}
            }
            result=max(count+1,result);
        }
        return result;
    }
};