class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>> timeslot;
    bool book(int startTime, int endTime) {
        for(auto it:timeslot){
            if(startTime<it.second && endTime>it.first){return false;}
        }
        timeslot.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */