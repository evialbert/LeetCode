class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        map<int, int> mp; // numbers that are present
        for(auto it: nums) mp[it]++;
        for(int i = 0; i < n; i++){
            mp[nums[i]]--; // decrease the count of current number as we are comparing next numbers.
            ans += mp[nums[i]]; // using 0 operation
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            while(s.size() < 7) s += '0';
            set<int> vals; // all the numbers that can be made by rearranging

            // one operation
            for(int k = 0; k < 7; k++){
                for(int j = k+1; j < 7; j++){
                    if(s[k] == s[j]) continue;
                    swap(s[k], s[j]);
                    reverse(s.begin(), s.end());
                    int cnt = stoi(s);
                    reverse(s.begin(), s.end());
                    if(mp.find(cnt) != mp.end()) vals.insert(cnt);
                    swap(s[k], s[j]);
                }
            }

            // two operation
            for(int p = 0; p < 7; p++){
                for(int j = p+1; j < 7; j++){
                    if (s[p] == s[j]) continue;
                    swap(s[p], s[j]);

                    for (int k = 0; k < 7; k++) {
                        for (int l = k + 1; l < 7; l++) {
                            if (s[k] == s[l] || (k == p && l == j)) continue;
                            swap(s[k], s[l]);  
                            reverse(s.begin(), s.end());
                            int cnt = stoi(s); 
                            reverse(s.begin(), s.end());
                            if (mp.find(cnt) != mp.end()) vals.insert(cnt);
                            swap(s[k], s[l]); 
                        }
                    }

                    swap(s[p], s[j]);
                }
            }
            for(auto it: vals) ans += mp[it];
        }

        return ans;
    }
};