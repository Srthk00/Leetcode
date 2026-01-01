class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        while(i>=0 && digits[i]==9){
            digits[i]=0;i--;
        }
        if(i>=0){digits[i]++;}
        else{
            digits.resize(digits.size()+1,0);
            digits[0]=1;
        }
        return digits;
    }
};