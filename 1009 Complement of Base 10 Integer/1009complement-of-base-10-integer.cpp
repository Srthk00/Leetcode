class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){return 1;}
        for(int i=1;i<32;i++){
            int allOnes=(1<<i)-1;
            if(n<=allOnes){
                return allOnes^n;
            }
        }
        return 1;
    }
};