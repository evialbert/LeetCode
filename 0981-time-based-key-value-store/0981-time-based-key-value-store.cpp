class TimeMap {
public:
    
    // declare a map
    
    unordered_map<string, map<int, string>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        // take the upper bound of timestamp
        
        auto it = mp[key].upper_bound(timestamp);
        
        // if there is no. timestamp <= given timestamp
        
        if(it == mp[key].begin())
        {
            return "";
        }
        
        it--;
        
        // find the time
        
        int time = it -> first;
        
        return mp[key][time];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */