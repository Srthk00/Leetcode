class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result=0;
        int mini=INT_MAX,n=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mini=min(mini,abs(matrix[i][j]));
                result+=abs(matrix[i][j]);
                if(matrix[i][j]<0){n++;}
            }
        }
        if(n%2==0){return result;}
        return result-(2*mini);
    }
};