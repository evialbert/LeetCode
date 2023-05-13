class FrequencyTracker {
public:
    map<int, int>m, m1;
    //vector<int>v;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        //v.push_back(number);
        if(m.find(number)!=m.end()){
            m1[m[number]]--;
            if(m1[m[number]]==0){
                m1.erase(m[number]);
            }
        }
        m[number]++;
        m1[m[number]]++;
    }
    
    void deleteOne(int number) {
        
        if(m.find(number)!=m.end()){
            // auto it=find(v.begin(), v.end(), number)-v.begin();
            // v.erase(v.begin()+it);
            m1[m[number]]--;
            if(m1[m[number]]==0){
                m1.erase(m[number]);
            }
            m[number]--;
            if(m[number]==0){
                m.erase(number);
            }
            else{m1[m[number]]++;}
        }
        
    }
    
    bool hasFrequency(int frequency) {
        if(m1[frequency]){return true;}
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */