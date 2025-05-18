class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            return a[0]<b[0];
        });
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