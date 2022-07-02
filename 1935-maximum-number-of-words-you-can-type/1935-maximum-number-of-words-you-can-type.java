class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        HashSet<Character> set=new HashSet<>();
        for(char ch:brokenLetters.toCharArray()){
            set.add(ch);
        }
        String[] l=text.split(" ");
        int count=l.length;
        for(int i=0;i<l.length;i++){
            for(char ch:l[i].toCharArray()){
                if(set.contains(ch)){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
}