class Solution {
    public String compressedString(String word) {
        int n = word.length(), count = 0, i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (j < n) {
            count = 0;
            while (j < n && word.charAt(i) == word.charAt(j) && count < 9) {
                j++;
                count++;
            }
            ans.append(count).append(word.charAt(i));
            i = j;
        }
        return ans.toString();
    }
}