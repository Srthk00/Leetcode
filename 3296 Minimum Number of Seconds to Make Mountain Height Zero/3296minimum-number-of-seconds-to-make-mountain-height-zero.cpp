class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& t) {
        // time, idx, timesDigged
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        for(int i=0;i<t.size();i++){
            pq.push({t[i],i,1});
        }
        while(h>0){
            auto tp=pq.top();
            pq.pop();
            h--;
            if(h==0){
                return tp[0];
            }
            long long times=tp[2]+1;
            long long newTime=(long long)t[tp[1]]*(times*(times+1)/2);
            pq.push({newTime,tp[1],(int)times});
        }
        return 0;
    }
};