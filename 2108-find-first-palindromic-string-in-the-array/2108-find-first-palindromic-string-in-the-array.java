class Solution {
    public String firstPalindrome(String[] words) {
        int i = 0;
        for(String word : words) {
            i = 0;
            while(i <= (word.length() / 2))
                if(word.charAt(i) != word.charAt(word.length() - ++i))
                    break;
            if(--i == (word.length() / 2))
                return word;
        }
        
        return "";
    }
}