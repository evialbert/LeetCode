class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        vector<int> match(n, 0);
        for (auto& word : words) {
            string s = word + "#" + target;
            int excess = word.size() + 1;
            int nn = s.size();
            // z-algorithm
            vector<int> z(nn);
            int x = 0, y = 0;
            for (int i = 1; i < nn; i++) {
                z[i] = max(0, min(z[i - x], y - i + 1));
                while (i + z[i] < nn && s[z[i]] == s[i + z[i]]) {
                    x = i;
                    y = i + z[i];
                    z[i]++;
                }
                if (i >= excess && z[i] > 0)
                    match[i - excess] = max(match[i - excess], z[i]);
            }
        }
        // greedy algorithm
        int steps =0,currend=0,farthest=0;
        for(int i=0; i<n; i++){
            farthest = max(farthest, i+match[i]);
            if(i==currend){
                steps++;
                currend =farthest;
                if(currend>=n)  break;
            }
        }
        // if we can't form the target
        if(currend<n)   return -1;
        return steps;
    }
};