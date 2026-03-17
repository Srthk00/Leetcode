class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int result=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    continue;
                }
                else{
                    if(matrix[i][j]==0){
                        continue;
                    }
                    else{
                        matrix[i][j]+=matrix[i-1][j];
                    }
                }
            }
            vector<int> temp=matrix[i];
            sort(temp.rbegin(),temp.rend());
            for(int k=0;k<temp.size();k++){
                if(temp[k]!=0){
                    int area=temp[k]*(k+1);
                    result=max(result,area);
                }
                else{
                    break;
                }
            }
        }
        return result;
    }
};