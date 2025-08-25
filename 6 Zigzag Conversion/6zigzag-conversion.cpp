class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){return s;}
        int n=s.size();
        string result="";
        vector<vector<char>> mat(numRows,vector<char>(n,'#'));
        int i=0;
        int a=-1,b=0;
        while(i<n){
            while(a<numRows-1 && i<n){
                mat[++a][b]=s[i++];
            }
            while(a>0 && i<n){
                mat[--a][++b]=s[i++];
            }
        }
        for(int x=0;x<numRows;x++){
            for(int y=0;y<n;y++){
                if(mat[x][y]!='#'){
                    result+=mat[x][y];
                }
            }
        }
        return result;
    }
};