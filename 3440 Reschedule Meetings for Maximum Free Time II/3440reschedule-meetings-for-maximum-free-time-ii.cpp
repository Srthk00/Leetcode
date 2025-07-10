class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> freetime;
        freetime.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            freetime.push_back(startTime[i]-endTime[i-1]);
        }
        freetime.push_back(eventTime-endTime[n-1]);
        int m=freetime.size();
        vector<int> prefix(m),suffix(m);
        prefix[0]=0;
        for(int i=1;i<m;i++){
            prefix[i]=max(freetime[i-1],prefix[i-1]);
        }
        suffix[m-1]=0;
        for(int i=m-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],freetime[i+1]);
        }
        int result=0;
        for(int i=1;i<m;i++){
            int meeting=endTime[i-1]-startTime[i-1];
            if(meeting<=max(prefix[i-1],suffix[i])){
                result=max(result,freetime[i-1]+freetime[i]+meeting);
            }
            else{
                result=max(result,freetime[i-1]+freetime[i]);
            }
        }
        return result;
    }
};