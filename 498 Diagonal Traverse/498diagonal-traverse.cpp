class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> result;
        int t=1;
        for(int d=0;d<m+n-1;d++){
            int i=d>=n?(t++):0;
            int j=d<n?d:n-1;
            vector<int> currdiag;
            while(i<m && j>=0){
                currdiag.push_back(mat[i++][j--]);
            }
            if(d%2==0){
                reverse(currdiag.begin(),currdiag.end());
            }
            result.insert(result.end(), currdiag.begin(), currdiag.end());
        }
        return result;
    }
};