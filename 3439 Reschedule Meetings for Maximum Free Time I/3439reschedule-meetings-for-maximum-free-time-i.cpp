class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> freetime;
        freetime.push_back(startTime[0]-0);
        for(int i=1;i<n;i++){
            freetime.push_back(startTime[i]-endTime[i-1]);
        }
        freetime.push_back(eventTime-endTime[n-1]);
        int i=0,j=k;
        if(j>=freetime.size()){
            return accumulate(freetime.begin(),freetime.end(),0);
        }
        int result=accumulate(freetime.begin(),freetime.begin()+k+1,0);
        int temp=result;
        while(j<freetime.size()-1){
            temp-=freetime[i];
            i++;j++;
            temp+=freetime[j];
            result=max(result,temp);
        }
        return result;
    }
};