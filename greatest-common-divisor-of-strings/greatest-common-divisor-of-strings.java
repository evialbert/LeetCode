class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length(), len2 = str2.length();
        if (len1 == 0) return str2;
        if (len1 < len2) return gcdOfStrings(str2, str1);
        if(!str1.startsWith(str2)) return "";
        return gcdOfStrings(str1.substring(len2, len1), str2);
    }
}