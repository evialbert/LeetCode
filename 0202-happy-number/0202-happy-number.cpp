class Solution {
public:
    bool isHappy(int n) {
        std::set<int> seen;
        do {
            seen.insert(n);
            int digitsum = 0;
            int nc = n;
            while (nc != 0) {
                int digit = nc % 10;
                digitsum += digit * digit;
                nc /= 10;
            }
            
            n = digitsum;
            
            if (n == 1) {
                return true;
            }
        } while (seen.find(n) == seen.end());
        return false;
    }
};