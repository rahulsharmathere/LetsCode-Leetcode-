class TaskManager {
public:
    map<int,pair<int,int>>mp; // tid ,uid,pr
    set<pair<int,int>>st;// pr,tid
    TaskManager(vector<vector<int>>& tasks) {
        // uid,tid,pr
        for(auto it:tasks){
            mp[it[1]]={it[0],it[2]};
            st.insert({it[2],it[1]});
        }
    }
    
    void add(int userId, int taskId, int pr) {
        mp[taskId]={userId,pr};
        st.insert({pr,taskId});
    }
    
    void edit(int taskId, int newPr) {
        pair<int,int>p=mp[taskId];
        mp[taskId]={p.first,newPr};
        st.erase({p.second,taskId});
        st.insert({newPr,taskId});
    }
    
    void rmv(int taskId) {
        pair<int, int> p = mp[taskId];     
        mp.erase(taskId);
        st.erase({p.second, taskId});     
    }
    
    int execTop() {
        if (mp.empty()) return -1;
        auto it = st.end();
        it--;                              
        pair<int, int> p = *it;
        int ans = mp[p.second].first;      
        mp.erase(p.second);                
        st.erase(it);                      
        return ans;
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