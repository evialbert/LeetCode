class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0;
        int ans = 0;
        for(char& c : s)
        {
            if(c == 'b')
                count++;
            else
                ans = min(ans + 1, count);
        }
        return ans;
    }
};