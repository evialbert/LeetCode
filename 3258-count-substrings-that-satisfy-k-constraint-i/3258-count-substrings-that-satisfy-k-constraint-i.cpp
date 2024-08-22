class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l = 0, r = 0, c0 = 0, c1 = 0, cnt = 0;
        while(r < s.length()){
            if(s[r] == '1') c1++;
            else c0++;
            while(c1 > k && c0 > k){
                if(s[l] == '1') c1--;
                else c0--;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();