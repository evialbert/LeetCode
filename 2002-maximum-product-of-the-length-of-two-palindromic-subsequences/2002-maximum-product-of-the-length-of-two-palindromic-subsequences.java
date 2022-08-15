class Solution {
    private int maxProduct;

    public int maxProduct(String s) {
        maxProduct = 0;
        populateMaxProduct(s, new StringBuilder(), new StringBuilder(), 0);
        return maxProduct;
    }

    private void populateMaxProduct(String s, StringBuilder s1, StringBuilder s2, int pos) {
        int length = s.length();
        if(pos == length) {
            if(isPalindrome(s1.toString()) && isPalindrome(s2.toString())) {
                maxProduct = Math.max(maxProduct, (s1.length() * s2.length()));
            }
            return;
        }
        char ch = s.charAt(pos);
        s1.append(ch);
        populateMaxProduct(s, s1, s2, (pos + 1));
        s1.deleteCharAt(s1.length() - 1);
        s2.append(ch);
        populateMaxProduct(s, s1, s2, (pos + 1));
        s2.deleteCharAt(s2.length() - 1);
        populateMaxProduct(s, s1, s2, (pos + 1));
    }

    private boolean isPalindrome(String s) {
        int low = 0, high = (s.length() - 1);
        while(low < high) {
            if(s.charAt(low) != s.charAt(high)) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
}