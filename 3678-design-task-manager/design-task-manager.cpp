class TaskManager {
public:
    map<int,set<pair<int,int>>> mp; // priority to set of {userid, taskid}
    map<int,pair<int,int>> t; // task to {priority, userid}
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task:tasks){
            add(task[0],task[1],task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[priority].insert({taskId, userId});
        t[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        auto [oldP, userId] = t[taskId];
        t.erase(taskId);
        mp[oldP].erase({taskId, userId});
        if(mp[oldP].size() == 0)
        mp.erase(oldP);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        auto [oldP, userId] = t[taskId];
        t.erase(taskId);
        mp[oldP].erase({taskId, userId});
        if(mp[oldP].size() == 0)
        mp.erase(oldP);
    }
    
    int execTop() {
        if(mp.size() == 0)
        return -1;
        auto oldP = (mp.rbegin())->first;
        auto [taskId, userId] = *((mp.rbegin())->second).rbegin();
        t.erase(taskId);
        mp[oldP].erase({taskId, userId});
        if(mp[oldP].size() == 0)
        mp.erase(oldP);
        return userId;
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