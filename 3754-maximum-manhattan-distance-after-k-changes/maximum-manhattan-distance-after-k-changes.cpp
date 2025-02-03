class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        unordered_map<char, int> dir;
        
        for (char c : s) {
            ++dir[c];

            int vmin = min(dir['N'], dir['S']);
            int vmax = max(dir['N'], dir['S']);
            int hmin = min(dir['W'], dir['E']);
            int hmax = max(dir['W'], dir['E']);

            int d1 = min(k, vmin);
            int d2 = min(k - d1, hmin);
    
            int dist = vmax - vmin + 2 * d1 + hmax - hmin + 2 * d2;
            result = max(result, dist);
        }

        return result;
    }
};