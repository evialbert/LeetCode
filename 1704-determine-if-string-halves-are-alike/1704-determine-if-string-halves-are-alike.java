class Solution {
    public boolean halvesAreAlike(String s) {
        s = s.toLowerCase();
        String s1 = s.substring(0, s.length()/2); // first half of the string
        String s2 = s.substring(s.length()/2); // second half of the string
        
        // checking the two strings vowel count
        if(getVowelCount(s1) == getVowelCount(s2)) {
            return true;
        }
        return false;
    }
    
    // getting vowel count of the string
    public int getVowelCount(String str) {
        int count = 0;
        for(char c : str.toCharArray()) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
        }
        return count;
    }
}