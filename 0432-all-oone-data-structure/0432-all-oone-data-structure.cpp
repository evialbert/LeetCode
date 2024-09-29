class AllOne {
public:
    unordered_map<string,int>mpp;
    set<pair<int,string>> st;

    AllOne() {
        
    }
    
    void inc(string key) {
        int cnt = mpp[key]; //current count of key
        mpp[key]++;
        st.erase({cnt,key}); //remove old pair from set if key exists
        st.insert({cnt + 1,key}); // insert new pair with updated count
    }
    
    void dec(string key) {
        int cnt = mpp[key]; //current count of key
        mpp[key]--;
        st.erase({cnt,key}); //remove old pair from set if key exists
        if(mpp[key] > 0){
           st.insert({cnt - 1,key}); // insert new pair with updated count
        }
        
    }
    
    string getMaxKey() {
        if(st.size()>0) return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(st.size()>0) return st.begin()->second;
        return "";
    }
};
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */