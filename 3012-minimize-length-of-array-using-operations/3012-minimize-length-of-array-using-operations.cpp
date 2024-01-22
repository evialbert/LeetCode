class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int cnt = 0;
        for(int &num : nums) {
            if(num == minNum) {
                ++cnt;
            } else if(num % minNum != 0) {
                return 1;
            }
        }
        return (cnt/2 + cnt%2);
    }
};