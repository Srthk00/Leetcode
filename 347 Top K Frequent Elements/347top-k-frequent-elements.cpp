class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int i:nums){
            map[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &i:map){
            pq.push({i.second,i.first});
        }
        vector<int> result;
        while(k>0){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};