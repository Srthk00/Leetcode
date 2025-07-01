class Solution {
public:
    int possibleStringCount(string word) {
        int result=1;
        int i=0;
        while(i<word.size()){
            char curr=word[i];
            int freq=1;
            while(i<word.size()-1 && curr==word[i+1]){
                freq++;
                i++;
            }
            if(freq>1){
                result+=freq-1;
            }
            i++;
        }
        return result;
    }
};