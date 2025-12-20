class Solution {
public:
    bool check(vector<string> &strs,int x){
        for(int i=1;i<strs.size();i++){
            if(strs[i-1][x]>strs[i][x]){return true;}
        }
        return false;
    }

    int minDeletionSize(vector<string>& strs) {
        int result=0;
        for(int i=0;i<strs[0].size();i++){
            if(check(strs,i)){result++;}
        }
        return result;
    }
};