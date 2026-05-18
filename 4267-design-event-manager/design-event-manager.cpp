struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

class EventManager {
public:
    set<pair<int, int>, cmp> st;
    unordered_map<int, int> mp;
    
    EventManager(vector<vector<int>>& events) {
        for (auto &e : events) {
            st.insert({e[1], e[0]});
            mp[e[0]] = e[1]; 
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (mp.count(eventId)) {
            int old = mp[eventId];
            st.erase({old, eventId});
            mp[eventId] = newPriority;
            st.insert({newPriority, eventId});
        }
    }
    
    int pollHighest() {
        if (st.empty()) return -1;
        auto it = prev(st.end());
        int ans = it->second;
        mp.erase(ans);
        st.erase(it);
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */