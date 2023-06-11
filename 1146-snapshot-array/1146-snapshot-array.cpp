class SnapshotArray {
public:
    map<int,map<int,int>>m;
    int ct=0;
    SnapshotArray(int length) {
       
    }
    
    void set(int index, int val) {
        m[index][ct]=val;
    }
    
    int snap() {
        ct++;
        return ct-1;
    }
    
    int get(int index, int snap_id) {
        
        
        if(m[index].size() == 0) return 0;
        if(snap_id<m[index].begin()->first) return 0; // initially all values is set to 0;
        
        auto idx = m[index].upper_bound(snap_id);
        
        idx--;
        
        return idx->second;
        
    }
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */