class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        backtrack(s, res, 0, 0, "");
        return res;
    }

    public void backtrack(String s, List<String> res, int dots, int i, String curIp) {
        if (dots > 4) return;  
        
        int n = s.length();
        if (dots == 4 && i == n) {  
            res.add(curIp.substring(0, curIp.length() - 1));  
            return;
        }

        for (int j = i; j < Math.min(i + 3, s.length()); j++) {
            String segment = s.substring(i, j + 1);
            if (Integer.parseInt(segment) <= 255 && (segment.equals("0") || s.charAt(i) != '0')) {
                backtrack(s, res, dots + 1, j + 1, curIp + segment + ".");
            }
        }
    }
}