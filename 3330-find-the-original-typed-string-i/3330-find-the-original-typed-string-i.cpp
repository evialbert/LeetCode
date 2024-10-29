class Solution {
public:
    int possibleStringCount(const string& word) {
        int count = 0;
        char prev = word.front();
        for(char curr : word) {
            if(curr == prev) ++count;
            prev = curr;
        }
        return count;
    }
};