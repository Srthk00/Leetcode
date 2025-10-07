class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> result; 
        vector<int> zeros;
        // lake: day in which it rains on that lake(index in rains)
        unordered_map<int,int> lakes;
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0){
                zeros.push_back(i);
                result.push_back(1);
            }
            else if(lakes.find(rains[i])==lakes.end() || lakes[rains[i]]==-1){
                lakes[rains[i]]=i;
                result.push_back(-1);
            }
            else{
                int prevrain=lakes[rains[i]];
                auto it=upper_bound(zeros.begin(),zeros.end(),prevrain);
                if(it==zeros.end()){return {};}
                int idx=*it;
                result[idx]=rains[i];
                zeros.erase(it);
                result.push_back(-1);
                lakes[rains[i]]=i;
            }
        }
        return result;
    }
};