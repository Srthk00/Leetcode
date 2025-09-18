class TaskManager {
public:
    // priority,taskID
    priority_queue<pair<int,int>> pq;
    // task={userID,priority}
    unordered_map<int,pair<int,int>> taskmap;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &it:tasks){
            int u=it[0];
            int t=it[1];
            int p=it[2];
            add(u,t,p);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskmap[taskId]={userId,priority};
        pq.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int u=taskmap[taskId].first;
        taskmap[taskId]={u,newPriority};
        pq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        taskmap[taskId]={-1,-1};
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [p,t]=pq.top();
            pq.pop();
            if(p==taskmap[t].second){
                int temp=taskmap[t].first;
                taskmap[t]={-1,-1};
                return temp;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */