class Solution {
    public boolean checkOnesSegment(String s) {
     int n=s.length();
  for(int i=1;i<n;i++)
  {    //finding "01" combination
      if(s.charAt(i-1)==48 && s.charAt(i)==49)
          return false;
  }
  
  return true;    
    }
}