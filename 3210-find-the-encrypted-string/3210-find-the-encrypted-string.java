class Solution {
    public String getEncryptedString(String s, int k) {
                int m = k % s.length();
        String or =s;
        StringBuilder sb = new StringBuilder();
        s = s.concat(s);

        for (int i = 0; i < or.length(); i++) {
            sb.append(s.charAt(i + m));
        }
        return sb.toString();
    }
}