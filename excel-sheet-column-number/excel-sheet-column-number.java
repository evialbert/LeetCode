class Solution {
    public int titleToNumber(String s) {
      int res=0;
   for(int i=0;i<s.length()-1;i++){
       res+=s.charAt(i)-'A'+1;
       res*=26;
   }
   return res+s.charAt(s.length()-1)-'A'+1;  
    }
}