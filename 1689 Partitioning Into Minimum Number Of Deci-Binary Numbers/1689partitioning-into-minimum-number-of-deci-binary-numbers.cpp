class Solution {
public:
    int minPartitions(string n) {
        int result=0;
        for(char ch:n){
            result=max(result,ch-'0');
        }
        return result;
    }
};