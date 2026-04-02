class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& neww) {
        int n=intervals.size();
        if(n==0){
            return {neww};
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=neww[0]){
                flag=true;
                intervals.insert(intervals.begin()+i,neww);
                break;
            }
        }
        if(!flag){
            intervals.push_back(neww);
        }
        vector<vector<int>> result;
        vector<int> temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=temp[1]){
                temp[1]=max(intervals[i][1],temp[1]);
            }
            else{
                result.push_back(temp);
                temp=intervals[i];
            }
        }
        result.push_back(temp);
        return result;
    }
};