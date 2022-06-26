class Solution {
    public boolean makeEqual(String[] words) 
    {
     int a[]=new int[26];
     int n=words.length;
     for(int i=0; i<words.length; i++)
     {
         String str=words[i];
         for(int j=0; j<str.length(); j++)
         {
             a[str.charAt(j)-'a']++;
         }
     }
     for(int i=0; i<26; i++)
     {
         if(a[i]%n!=0)return false;
     }
    return true;
    }
}