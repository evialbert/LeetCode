class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstOcc;
        int ans = -1;

        for(int i=0; i<s.size(); i++){
            char& c = s[i];
            if(firstOcc.contains(c)){
                ans = max(ans, i-firstOcc[c]-1);
            } else {
                firstOcc[c] = i;
            }
        }

        return ans;
    }
};