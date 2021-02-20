class Solution {
     public String convertToTitle(int n) {
        String result = "";
        while (n != 0) {
            int tmp = (n - 1) % 26;
            result = (char)('A' + tmp) + result;
            n = (n - 1)/ 26;
        }
        return result;
    }
}