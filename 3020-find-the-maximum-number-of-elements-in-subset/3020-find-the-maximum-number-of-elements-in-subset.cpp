class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, long long> m;
        long long ans = 1;

        for (long long n : nums) m[n]++;

        for (auto it = m.begin(); it != m.end(); ++it) {
            long long f = it->first;
            long long count = 1;  
            if(f != 1){
            while (m[f] > 1 && m.find(f * f) != m.end()) {
                f *= f;  
                count+=2;
            }
            }
            else{
                while(m[f] > 2){
                   m[f] -= 2;
                    count+=2;
                }
            }
            ans = max(ans, count);
        }

        return ans;
    }
};