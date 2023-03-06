class Solution {
public:
    bool isReachable(int targetX, int targetY) {
    return __builtin_popcount(__gcd(targetX,targetY))==1;
    }
};