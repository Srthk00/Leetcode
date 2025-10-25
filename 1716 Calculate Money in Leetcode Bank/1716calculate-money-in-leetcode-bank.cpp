class Solution {
public:
    int totalMoney(int n) {
        int weeks=n/7;
        int result=0;
        int days=n%7;
        result+=(weeks*(2*28+(weeks-1)*7))/2;
        int i=weeks+1;
        while(days-->0){
            result+=i++;
        }
        return result;
    }
};