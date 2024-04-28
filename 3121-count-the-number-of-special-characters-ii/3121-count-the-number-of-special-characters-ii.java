class Solution {
    public int numberOfSpecialChars(String word) {

        int cap[]=new int [26];
        int smal[]=new int [26];

        for (int i=0;i<word.length();i++){
          char c=word.charAt(i);
          if (Character.isLowerCase(c)){
              int val=c-'a';
              if (cap[val]==0){
                smal[val]=1;
              } 
              else {
                smal[val]=0;
              }
              }

              else{
                int capVal=c-'A';
                cap[capVal]=1;
              }
          }
        
        int sum =0;
        for (int i=0;i<26;i++){
          int x=smal[i];
          int y=cap[i];
          sum+=Math.min(x,y);
        }
      
        return sum;
    }
}