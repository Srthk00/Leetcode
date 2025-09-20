class Router {
public:
    int SIZE;
    queue<string> que;
    unordered_map<string,vector<int>> datamap;
    unordered_map<int,vector<int>> destmap;
    Router(int memoryLimit) {
        SIZE=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key=to_string(source)+" "+to_string(destination)+" "+to_string(timestamp);
        if(datamap.find(key)!=datamap.end()){return false;}
        if(que.size()>=SIZE){
            string k=que.front();
            vector<int> packet=datamap[k];
            que.pop();
            datamap.erase(k);
            auto &temp=destmap[packet[1]];
            temp.erase(temp.begin());
            if(temp.empty()){
                destmap.erase(packet[1]);
            }
        }
        que.push(key);
        datamap[key]={source,destination,timestamp};
        destmap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(que.empty()){return {};}
        string key=que.front();
        que.pop();
        vector<int> packet=datamap[key];
        datamap.erase(key);
        auto &temp=destmap[packet[1]];
        temp.erase(temp.begin());
        if(temp.empty()){
            destmap.erase(packet[1]);
        }
        return packet;
    }
    
    int getleft(vector<int> &nums,int low,int high,int i){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<i){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }

    int getright(vector<int> &nums,int low,int high,int i){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=i){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }

    int getCount(int destination, int startTime, int endTime) {
        vector<int> &nums=destmap[destination];
        if(nums.empty()){return 0;}
        int low=0,high=nums.size()-1;
        return getright(nums,low,high,endTime)-getleft(nums,low,high,startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */