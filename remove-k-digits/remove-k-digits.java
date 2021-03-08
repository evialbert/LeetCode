class Solution {
    public String remove(String num, int k) {
        if (k == 0) return num;
        if (num.length() == k) return "";
        char c = num.charAt(0);
        int index = 0;
        for (int i = 1; i <= k; i++) {
            if (num.charAt(i) < c) {
                c = num.charAt(i);
                index = i;
            }
        }
        return c + remove(num.substring(index + 1), k - index);
    }
    public String removeKdigits(String num, int k) {
        int n = num.length();
        if (n == k) return "0";
        String d = remove(num, k);
        
        while (d.charAt(0) == '0' && d != "0") {
            d = d.length() > 1 ? d.substring(1) : "0";
        }
        return d;
    }
}