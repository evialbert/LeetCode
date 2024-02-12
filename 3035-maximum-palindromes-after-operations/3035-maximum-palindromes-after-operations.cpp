class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<char, int> mp;
        vector<int> vec;
        for(auto it : words){
            vec.push_back(it.size());
            for(auto gt : it)
                mp[gt]++;
        }
        sort(vec.begin(), vec.end());
        int mxCnt = 0;
        for(auto it : vec){
            int odd_pos = it & 1, even_pairs = it / 2;
            for(auto &[x, y] : mp){ 
                if(!even_pairs && !odd_pos)
                    break;
                if(odd_pos && (y & 1)){
                    odd_pos = 0;
                    y--;
                }
                int eP = y / 2;
                int mini = min(even_pairs, eP);
                y -= mini * 2;
                even_pairs -= mini;
            }
            if(even_pairs > 0)
                break;
            mxCnt++;
        }
        return mxCnt;
    }
};