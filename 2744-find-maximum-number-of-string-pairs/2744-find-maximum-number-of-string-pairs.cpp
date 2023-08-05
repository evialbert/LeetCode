class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n  = words.size();
        unordered_map<string, int> mp;
        //add words to the map
        for(int i = 0; i < n; i++){
            mp[words[i]]++;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            // if reverse is present and is not equal (eg "zz")
            if(words[i] != temp){
                if(mp.count(temp) > 0){
                    ans++;
                    // reducing the count to remove duplicates
                    mp[temp]--;
                    mp[words[i]]--;
                    // if count is zero we remove it
                    if(mp[temp] == 0)
                        mp.erase(temp);
                    if(mp[words[i]] == 0)
                        mp.erase(words[i]);
                }
            }
        }
        return ans;
    }
};