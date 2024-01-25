class Solution {
    public int minimumPushes(String word) {
        final int LEN = 8;
        int[] buckets = new int[26];
        int total = 0, res = 0;
        for(char c: word.toCharArray()){
            int idx = c - 'a';
            if(buckets[idx] == 0){
                total++;
                buckets[idx] = total;
            }
            res += (buckets[idx] - 1) / LEN + 1;
        }
        return res;
        
    }
}