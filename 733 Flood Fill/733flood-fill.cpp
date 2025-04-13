class Solution {
public:
    void fill(vector<vector<int>> &image,vector<vector<int>> &result,int sr,int sc,int icolor,int color){
        int m=image.size();
        int n=image[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n|| image[sr][sc]!=icolor || result[sr][sc]==color)
            return;
        result[sr][sc]=color;
        fill(image,result,sr+1,sc,icolor,color);
        fill(image,result,sr-1,sc,icolor,color);
        fill(image,result,sr,sc+1,icolor,color);
        fill(image,result,sr,sc-1,icolor,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int icolor=image[sr][sc];
        vector<vector<int>> result=image;
        if(icolor!=color){
            fill(image,result,sr,sc,icolor,color);
        }
        return result;
    }
};