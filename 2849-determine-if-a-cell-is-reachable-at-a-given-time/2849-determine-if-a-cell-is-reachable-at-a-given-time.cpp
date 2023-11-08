class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1) return false;
        if(abs(sx - fx) <= t && abs(sy - fy) <= t) return true;
        return false;
    }
};