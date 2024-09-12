class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(auto ch: allowed){
            int bit = 1<<(ch-'a');
            mask = mask | bit;
        }
        int cnt = 0;
        for(auto word: words){
            bool flag = true;
            for(auto ch: word){
                int bit = 1<<(ch-'a');
                if((mask & bit) == 0){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};