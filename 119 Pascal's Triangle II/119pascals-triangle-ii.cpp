class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int index=rowIndex;
        vector<vector<int>> pascal;
        pascal.push_back({1});
        if(rowIndex==0){
            return pascal[0];
        }
        pascal.push_back({1,1});
        if(rowIndex==1){
            return pascal[1];
        }
        rowIndex--;
        while(rowIndex-->0){
            vector<int> prev=pascal.back();
            vector<int> curr;
            curr.push_back(1);
            for(int i=0;i<prev.size()-1;i++){
                curr.push_back(prev[i]+prev[i+1]);
            }
            curr.push_back(1);
            pascal.push_back(curr);
        }
        return pascal[index];
    }
};