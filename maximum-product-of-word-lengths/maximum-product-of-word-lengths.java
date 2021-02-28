class Solution {
    public int maxProduct(String[] words) {
        ArrayList<Integer> list=new ArrayList();
        int max=0;
     for(int i =0;i<words.length;i++)
     {
         for(int j=i+1;j<words.length;j++)
         {
             boolean ans= hasSameChar(words[i], words[j]);
             if(ans)
             {
                 int prod=(words[i].length()) *(words[j].length());
                if(max<prod)
                {
                    max=prod;   
                }
             }
         }
  }
     return max;       
    }
    
 boolean hasSameChar(String str1, String str2){
     
   for(char c : str1.toCharArray()){
      if(str2.indexOf(c) >= 0 ) 
    {
         return false;
    }
  }
  return true;
}    
}