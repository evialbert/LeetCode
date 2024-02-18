class Solution {
    public String lastNonEmptyString(String s) {
        Map<Character,Integer> m=new HashMap<>();
        for(int i=0;i<s.length();i++)
        {
            m.put(s.charAt(i),m.getOrDefault(s.charAt(i),0)+1);
        }
       int max=0;
        for(char a: m.keySet())
        {
            max=Math.max(max,m.get(a));
        }  
   int[] alp=new int[123];
   int[] supp=new int[s.length()];
   for(int i=0;i<s.length();i++)
   {    alp[s.charAt(i)]++;
       supp[i]=alp[s.charAt(i)];
      
   }
   String ans="";
   for(int i=0;i<s.length();i++)
   {
       if(supp[i]==max)
        ans=ans+s.charAt(i);
   }
   return ans;
    }
}