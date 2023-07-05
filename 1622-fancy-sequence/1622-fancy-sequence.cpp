class Fancy {
public:
    int mod = 1e9+7;
    // heap {val, inc, mult}
	// a[0] is a dummy node
    vector <array<long, 3>> a = {{0, 0, 1}};
    Fancy() {}
    void update(int i, int inc, int m) { // O(1)
        if (i >= a.size())
            return ;
        a[i][1] = (a[i][1] * m + inc) % mod;
        a[i][2] = (a[i][2] * m) % mod;
    }
    void append(int val) { // O(logN)
        a.push_back({0, 0, 0}); // dummy append 
        getIndex(a.size() - 2); // lazy path cleanup
        a.back() = {val, 0, 1}; // set new value
    }
    void addAll(int inc) { // O(1)
        update(1, inc, 1);
    }
    void multAll(int m) { // O(1)
        update(1, 0, m);
    }
    int getIndex(int idx) { // O(logN)
        if (idx >= a.size() - 1)
            return -1;
        int i = idx + 1, j = 1;
        int len = log2(i) + 1;
        for (int k = len - 1; k >= 0; k--) { 
            a[j][0] = (a[j][0] * a[j][2] + a[j][1]) % mod;
            update(j * 2    , a[j][1], a[j][2]);
            update(j * 2 + 1, a[j][1], a[j][2]);
            a[j][2] = 1; a[j][1] = 0; // reset
            int path = k > 0 ? (i & (1 << (k - 1))) > 0 : 0;
            j = (j * 2) + path; 
        }
        return a[j / 2][0];
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */