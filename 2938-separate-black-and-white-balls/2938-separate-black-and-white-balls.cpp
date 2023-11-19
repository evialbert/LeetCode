class Solution {
public:
    //Time complexity: O(n)
    //Space complexity:O(1)
    long long minimumSteps(string s) {
        long long ans{0}, lastZeroIndex{-1};
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                int steps = i-lastZeroIndex-1;
                lastZeroIndex++;
                ans += steps;
            }
        }
        
        return ans;
    }
};