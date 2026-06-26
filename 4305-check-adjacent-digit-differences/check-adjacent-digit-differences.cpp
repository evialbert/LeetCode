class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string& s) {
        const int n=s.size();
        char prev=s[0];
        for(int i=1; i<n; i++){
            const char c=s[i];
            if (abs(c-prev)>2) return 0;
            prev=c;
        }
        return 1;
    }
};