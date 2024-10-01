class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        for (int num : arr) {
            int rem = ((num % k) + k) % k; 
            remainderCount[rem]++;
        }
        if (remainderCount[0] % 2 != 0) {
            return false;
        }
        
        for (int i = 1; i < k; ++i) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false; 
            }
        }
        
        return true;
    }
};