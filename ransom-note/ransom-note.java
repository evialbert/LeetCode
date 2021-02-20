class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int [] res=new int[26];
        for(int i=0;i<magazine.length();i++){
            res[magazine.charAt(i)-'a']++;
        }
        for(int i=0;i<ransomNote.length();i++){
            int k=--res[ransomNote.charAt(i)-'a'];
            if(k<0)
                return false;
        }
        return true;
    }
}