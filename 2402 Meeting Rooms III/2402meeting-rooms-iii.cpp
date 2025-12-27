class Solution {
public:
    typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> freq(n,0);
        priority_queue<int,vector<int>,greater<int>> free;
        priority_queue<P,vector<P>,greater<P>> used;
        for(int i=0;i<n;i++){
            free.push(i);
        }
        for(int i=0;i<meetings.size();i++){
            while(!used.empty() && used.top().first<=meetings[i][0]){
                free.push(used.top().second);
                used.pop();
            }
            if(!free.empty()){
                int room=free.top();
                free.pop();
                freq[room]++;
                P assign={meetings[i][1],room};
                used.push(assign);
            }
            else{
                P temp=used.top();
                used.pop();
                freq[temp.second]++;
                long long new_time=temp.first+(meetings[i][1]-meetings[i][0]);
                used.push({new_time,temp.second});
            }
        }
        int result=0;
        int max_meetings=freq[0];
        for(int i=1;i<n;i++){
            if(freq[i]>max_meetings){
                result=i;
                max_meetings=freq[i];
            }
        }
        return result;
    }
};