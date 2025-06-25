class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,string> map;
        vector<int> temp=score;
        sort(temp.begin(),temp.end(),greater<int>());
        vector<string> medals={"Gold Medal","Silver Medal","Bronze Medal"};
        for(int i=0;i<temp.size();i++){
            if(i<3){
                map[temp[i]]=medals[i];
            }
            else{
                map[temp[i]]=to_string(i+1);
            }
        }
        vector<string> result;
        for(int it:score){
            result.push_back(map[it]);
        }
        return result;
    }
};