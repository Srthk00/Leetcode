class ExamTracker {
public:
    // time : score
    vector<pair<long long,long long>> nums;
    ExamTracker() {
        nums.push_back({0,0});
    }
    
    void record(long long time, long long score) {
        long long n=nums.size();
        long long last=nums[n-1].second;
        nums.push_back({time,score+last});
    }
    
    long long totalScore(long long startTime, long long endTime) {
        long long low=0,high=nums.size()-1;
        long long x=nums.size();
        while(low<high){
            long long mid=low+(high-low)/2;
            if(nums[mid].first<startTime){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        x=low;
        long long y=-1;
        low=0,high=nums.size()-1;
        while(low<high){
            long long mid=low+(high-low+1)/2;
            if(nums[mid].first<=endTime){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        y=low;
        long long before=0;
        long long middle=0;
        if(startTime==0 || x==0 || x==nums.size()){before=0;}
        else{before=nums[x-1].second;}
        if(endTime==0 || y==0 || y==nums.size() || y==-1){middle=0;}
        else{middle=nums[y].second;}
        return middle-before;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */