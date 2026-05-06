class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        vector<vector<char>> result(n,vector<char>(m,'.'));
        for (int j=0;j<m;j++){
            int l=n-1;
            int k=m-1-j;
            for (int i=n-1;i>=0;i--){
                if(box[j][i]=='.'){continue;}
                else if(box[j][i]=='#'){
                    result[l--][k]='#';
                }
                else{
                    result[i][k]='*';
                    l=i-1;
                }
            }
        }
        return result;
    }
};