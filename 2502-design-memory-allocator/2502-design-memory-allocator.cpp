class Allocator {
    map<int, int> omem;
    unordered_map<int, vector<int>> valmap;
    int n;
public:
    Allocator(int n) {
        this->n = n;
        omem[n] = 1;
    }
    
    int allocate(int size, int mID) {
        int ind = 0;
        
        while(ind < n) {
            auto it = omem.lower_bound(ind);
            int nind = it->first, nsize = it->second;

            if(nind - ind >= size and !omem.count(ind)) {
                omem[ind] = size;
                valmap[mID].push_back(ind);
                break;
            }
            
            else
                ind = nind + nsize;
        }
        
        return ind >= n ? -1 : ind;
    }
    
    int free(int mID) {
        int ans = 0;
        
        for(int ind : valmap[mID]) {
            ans += omem[ind];
            omem.erase(ind);
        }
        
        valmap.erase(mID);
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */