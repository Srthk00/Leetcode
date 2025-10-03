class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result="";
        while(columnNumber>0){
            if(columnNumber<=26){
                result.push_back('A'+(columnNumber-1));
                reverse(result.begin(),result.end());
                return result;
            }
            int curr=columnNumber%26;
            if(curr==0){  
                result.push_back('Z');
                columnNumber=(columnNumber/26)-1;
            }
            else{
                result.push_back('A'+(curr-1));
                columnNumber=columnNumber/26;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};