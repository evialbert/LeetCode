class Solution {
    public String sortVowels(String s) {
        int[] count = new int[100];
        for(char c : s.toCharArray()) {
            if(isVowel(c))
                count[c - 'A']++;
        }
        
        StringBuilder ans = new StringBuilder();
        String vowelStr = "AEIOUaeiou";
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(!isVowel(s.charAt(i))) {
                ans.append(s.charAt(i));
            } else {
                while(count[vowelStr.charAt(j) - 'A'] == 0) {
                    j++;
                }
                ans.append(vowelStr.charAt(j));
                count[vowelStr.charAt(j) - 'A']--;
            }
        }
        return ans.toString();
    }
    
    boolean isVowel(Character ch) {
        return ch == 'A' ||ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
}