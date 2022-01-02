class Solution {
    public int maxVowels(String s, int k) {
        char[] str = s.toCharArray();
        int start;
        int vowels = 0;

        for(int i = 0; i < k; i++) {
            if (isVowel(str[i])) vowels++;
        }

        int maxVowels = vowels;

        for(int end = k; end < str.length; end++) {
            start = end - k;
            if(isVowel(str[end])) vowels++;
            if(isVowel(str[start])) vowels--;
            maxVowels = Math.max(maxVowels, vowels);
        }

        return maxVowels;
    }
    
    public boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}