class RandomizedSet {
public:
    unordered_map<int,int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)) return false; 
        m[val]++;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false; 
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        auto item = m.begin();
        advance(item, rand()%m.size());
        return item->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */