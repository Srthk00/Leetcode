class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp=[](pair<int,int> p1,pair<int,int> p2){
            return pow(p1.first,2)+pow(p1.second,2)<pow(p2.first,2)+pow(p2.second,2);
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(auto &i:points){
            pq.push({i[0],i[1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return result;
    }
};