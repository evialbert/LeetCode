class Solution {
    public long wonderfulSubstrings(String word) {
        long[] cnt = new long[1024];
        long res=0;
        int msk=0;
        cnt[0]=1;
        for(var ch:word.toCharArray()){
            msk^= 1<<(ch-'a');
            res += cnt[msk];
            for(int i=0; i<10; i++){
                res += cnt[msk ^ (1<<i)];
            }
            cnt[msk]++;
        }
        return res;
    }
}
