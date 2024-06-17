class Solution {
    public String clearDigits(String s) {
        StringBuilder sb = new StringBuilder(s);
        for (int idx = 0; idx < sb.length(); idx++) {
            char curr = sb.charAt(idx);
            if (curr >= '0' && curr <= '9') {
                sb.deleteCharAt(idx);
                sb.deleteCharAt(idx - 1);
                idx = 0;
            }
        }
        return sb.length() == 0 ? "" : sb.toString();
    }
}