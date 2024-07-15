class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int len = colors.length, cnt = 1, ans = 0;

        for(int idx = 1; idx < (len + k - 1); idx++) {
            if(colors[idx % len] != colors[(idx - 1)%len]){
                cnt++;
                if(cnt == k) {
                    ans++;
                    cnt -= 1;
                }
            } else {
                cnt = 1;
            }        
        }
        return ans;
    }
}