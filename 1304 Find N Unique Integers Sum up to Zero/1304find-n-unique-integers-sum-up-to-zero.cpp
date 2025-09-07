class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n,0);
        int x=(n/2)*(-1);
        for(int i=0;i<n/2;i++){
            result[i]=x;
            result[n-i-1]=((-1)*x);
            x++;
        }
        return result;
    }
};