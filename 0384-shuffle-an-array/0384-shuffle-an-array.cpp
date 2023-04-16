class Solution {
    vector<int> vec;
    int size;
    
public:
    Solution(vector<int>& nums) {
        size = nums.size();
        vec = nums;
    }
    
    vector<int> reset() {
        return vec;
    }
    
    vector<int> shuffle() {
        vector<int> temp = vec;
        int unshaffled = size;
        for(int i = size - 1; i >= 0; --i){
            int pos = rand() % unshaffled;
            swap(temp[i], temp[pos]);
            unshaffled--;
        }
        return temp;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */