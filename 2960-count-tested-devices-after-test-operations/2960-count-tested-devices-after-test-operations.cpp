class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int c = 0;
        int curr = 0;
        for(auto i:b) {
            if(i > curr) {
                c++;
                curr++;
            }
        }
        return c;
    }
};