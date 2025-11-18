class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool flag=true;
        for(int i=0;i<bits.size();i++){
            if(bits[i]==1){flag=false;i++;}
            else{flag=true;}
        }
        return flag;
    }
};