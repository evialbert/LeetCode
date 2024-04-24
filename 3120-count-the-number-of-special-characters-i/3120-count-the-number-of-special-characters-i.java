class Solution {
    public int numberOfSpecialChars(String word) {
        int ans=0;
        HashSet<Character> hs=new HashSet<>();
        for(int i=0;i<word.length();i++){
            if(Character.isUpperCase(word.charAt(i))) hs.add(word.charAt(i));
        }
        for(int i=0;i<word.length();i++){
            if(hs.contains((char)(word.charAt(i)-32))) {
                hs.remove((char)(word.charAt(i)-32));
                // System.out.println(i);
                ans++;
            }
            
        }
        return ans;
    }
}