class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> v(n, 0);
        int lvl = 0;
        
        for(int i=0; i<n; ++i) {
            if(seq[i] == '(') {
                lvl++;
                v[i] = lvl;
            } else {
                v[i] = lvl;
                lvl--;
            }    
        }
        
        for(int i=0; i<n; ++i) {
            v[i] = v[i] % 2 == 1 ? 0 : 1;
        }
        return v;
    }
};