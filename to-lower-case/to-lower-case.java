class Solution {
    public String toLowerCase(String str) {
        char[] chs = str.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            char ch = chs[i];
            if ((int)ch >= 65 && (int)ch <= 90) chs[i] += 32;
        }
        return new String(chs);
    }
}
