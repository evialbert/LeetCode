class Solution {
public:
    int maxOperations(string s) {
        int operationsCount = 0, onesCount = 0;
        bool hasOne = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                onesCount++;
                hasOne=1;
            }
            if (s[i] == '0' && hasOne == true) {
                 operationsCount += onesCount;
                 hasOne=0;
            }
        }

        

        return operationsCount;
    }
};
