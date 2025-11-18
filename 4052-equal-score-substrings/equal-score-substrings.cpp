class Solution {
public:
    bool scoreBalance(string s) {

        int n = s.length();

        for(int i = 0; i < n; i++) {

            int leftSum = 0;
            for(int a = 0; a <= i; a++){

                leftSum += (s[a] - 'a' + 1);
            }

            int rightSum = 0;

            for(int a = i + 1; a < n; a++) {
                rightSum += (s[a] - 'a' + 1);
            }

            
            if(leftSum == rightSum) {
                return true;
            }
        }

        return false;
    }
};