class SlidingMedian {
public:
    vector<long> medianSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) {
            return vector<long>(nums.size(), 0);
        }
        left = {};
        right = {};
        left_removed = {};
        right_removed = {};
        for(int i = 0; i < k; i++) {
            addNum(nums[i]);
        }
        int sz = nums.size();
        vector<long> output;
        output.reserve(sz - k);    
        output.push_back(findScore());
        for(int i = k; i < sz; i++) {
            removeNum(nums[i - k]);
            addNum(nums[i]);
            output.push_back(findScore());
        }
        return output;
    }
    void addNum(int num) {
        if(left.size() == 0 || num <= left.top()) {
            left.push(num);
            left_sum += num;
        } else {
            right.push(num);
            right_sum += num;
        }
        balance();
        clear();
    }
    void balance() {
        if(left.size() - left_removed.size() >= right.size() - right_removed.size() + 2) {
            right_sum += left.top();
            left_sum -= left.top();
            right.push(left.top());
            left.pop();
        }
        if(right.size() - right_removed.size() > left.size() - left_removed.size()) {
            right_sum -= right.top();
            left_sum += right.top();
            left.push(right.top());
            right.pop();
        }
    }
    void removeNum(int num) {
        if(num <= left.top()) {
            left_sum -= num;
            left_removed.push(num);
        } else {
            right_sum -= num; 
            right_removed.push(num);
        }
        balance();
        clear();
    }
    void clear() {
        // ensure that left_removed.top() <= left.top()
        while(!left_removed.empty() && left_removed.top() > left.top()) {
            right_removed.push(left_removed.top()); left_removed.pop();
        }
        // ensure that right_removed.top() >= left.top()
        while(!right_removed.empty() && right_removed.top() < left.top()) {
            left_removed.push(right_removed.top()); right_removed.pop();
        }
        // clear out anything invalid
        while(!left_removed.empty() && left.top() == left_removed.top()) {
            left.pop();
            left_removed.pop();
        }
        while(!right_removed.empty() && right.top() == right_removed.top()) {
            right.pop();
            right_removed.pop();
        }
    }
    int findMedian() {
        return left.top();
    }
    long findScore() {
        long median = findMedian();
        return median * (left.size() - left_removed.size()) - left_sum + right_sum - median * (right.size() - right_removed.size());
    }
    // for managing the median
    std::priority_queue<int, vector<int>> left;
    std::priority_queue<int, vector<int>> left_removed;
    std::priority_queue<int, vector<int>, std::greater<int>> right; 
    std::priority_queue<int, vector<int>, std::greater<int>> right_removed; 
    // for managing the left and right sum
    long left_sum = 0;
    long right_sum = 0;
    
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        SlidingMedian sm;
        vector<long> cost = sm.medianSlidingWindow(nums, x); 
        const size_t sz = cost.size();
        // choose k elements from cost, each one x apart 
        vector<long> dp(sz, 0);
        dp[0] = cost[0];
        for(size_t i = 1; i < sz; i++) {
            dp[i] = min(dp[i - 1], cost[i]); 
        }
        for(int i = 1; i < k; i++) {
            for(size_t j = sz - 1; j >= i * x; j--) {
                dp[j] = cost[j] + dp[j - x]; 
            }
            for(size_t j = i * x + 1; j < sz; j++) {
                dp[j] = min(dp[j], dp[j - 1]); 
            }
        }
        return dp[sz - 1];
    } 
};