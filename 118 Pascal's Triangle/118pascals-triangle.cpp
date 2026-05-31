class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        if(numRows==1){
            return pascal;
        }
        pascal.push_back({1,1});
        if(numRows==2){
            return {{1},{1,1}};
        }
        numRows-=2;
        while(numRows-->0){
            vector<int> prev=pascal.back();
            vector<int> curr;
            curr.push_back(1);
            for(int i=0;i<prev.size()-1;i++){
                curr.push_back(prev[i]+prev[i+1]);
            }
            curr.push_back(1);
            pascal.push_back(curr);
        }
        return pascal;
    }
};