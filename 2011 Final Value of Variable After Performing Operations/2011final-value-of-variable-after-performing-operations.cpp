class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result=0;
        for(string str:operations){
            if(str.find('+')!=string::npos){result++;}
            else{result--;}
        }
        return result;
    }
};