class Solution {
    static bool comparator(string &a, string &b){
        if(a.size() == b.size()){
            return a < b;
        }
        return a.size() <= b.size();
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comparator);
        return nums[n - k];
    }
};