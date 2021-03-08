class Solution {
    public String decodeString(String s) {
        if(s.isEmpty() || s.indexOf("[") == -1) return s;
        int idx = s.indexOf('['), l = idx - 1;
        String cnt = "";
        while(l >= 0 && s.charAt(l) >= '0' && s.charAt(l) <= '9')
            cnt = s.charAt(l--) + cnt;
        int num = Integer.valueOf(cnt);

        int r = idx, k = 0;
        while(r < s.length()) {
            if(s.charAt(r) == '[') k++;
            else if(s.charAt(r) == ']') k--;
            if(k == 0) break;
            r++;
        }

        String left = decodeString(s.substring(0, l + 1)), right = decodeString(s.substring(r + 1));
        String mid = decodeString(s.substring(idx + 1, r));
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < num; i++) {
            sb.append(mid);
        }        
        return left + sb.toString() + right;
    }
}