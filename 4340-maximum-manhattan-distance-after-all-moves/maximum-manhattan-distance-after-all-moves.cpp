class Solution {
public:
    int maxDistance(string& moves) {
        int x=0, y=0, wildcard=0;
        for(char c: moves){
            x+=(c=='R')-(c=='L');
            y+=(c=='U')-(c=='D');
            wildcard+=(c=='_');
        }
        return abs(x)+abs(y)+wildcard;
    }
};