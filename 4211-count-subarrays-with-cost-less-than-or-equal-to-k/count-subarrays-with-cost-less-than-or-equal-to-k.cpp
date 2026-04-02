class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long l = 0, r = 0;
        long long maxi = 0ll;
        long long mini = 1e10;
        long long  c = 0;
         multiset<long long> st;
        while (r < n) {
            st.insert(nums[r]);
           
            while ((*prev(st.end()) - *st.begin()) * (r - l + 1) > k) {
                st.erase(st.find(nums[l]));
                l++;
            }
            c+=(r-l+1);
            r++;
        }
        return c;
    }
};