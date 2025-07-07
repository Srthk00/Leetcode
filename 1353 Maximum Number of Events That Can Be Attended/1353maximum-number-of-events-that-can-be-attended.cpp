class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        int day=events[0][0];
        int result=0;
        int i=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(!pq.empty() || i<events.size()){
            if(pq.empty()){
                day=events[i][0];
            }
            while(i<events.size() && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                result++;
                pq.pop();
            }
            day++;
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }
        return result;
    }
};