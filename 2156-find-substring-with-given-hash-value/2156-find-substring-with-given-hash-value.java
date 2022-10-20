class Solution {
    public String subStrHash(String s, int power, int modulo, int k, int hashValue) {
        long[] pk = new long[k];
        pk[0] = 1;
        for(int i = 1; i < k; i++){
            pk[i] = (power * pk[i - 1]) % modulo;
        }
        long val = 0;
        for(int i = s.length() - k; i < s.length(); i++){
            val += ((s.charAt(i) - 'a' + 1) * pk[i - (s.length() - k)]) % modulo;
            val %= modulo;
        }
        String res = "";
        if((int)val == hashValue) res = s.substring(s.length() - k);
        for(int i = s.length() - k - 1; i >= 0; i--){
            val += modulo - (((s.charAt(i + k) - 'a' + 1) * pk[k - 1]) % modulo);
            val = (val * power) % modulo;
            val += s.charAt(i) - 'a' + 1;
            val %= modulo;
            if((int)val == hashValue) res = s.substring(i, i + k);
        }
        return res;
    }
}