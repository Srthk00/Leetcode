class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int result=0;
        for(char ch:s){
            if(ch=='('){
                open++;
            }
            else{
                open==0?result++:open--;
            }
        }
        return result+open;
    }
};