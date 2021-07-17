class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        if(shifts.length == 0) return "";
        int n = shifts.length;
        int prefix[] = new int[n]; 
        prefix[n - 1] = shifts[n - 1];
      
        for(int i = n-2; i>=0 ;i--){
             prefix[i] = (prefix[i+1] + shifts[i])%26;
        }
      
        StringBuilder res = new StringBuilder(); 
        for(int i = 0 ; i<s.length() ;i++){
            char toAppend;
            if(i < prefix.length){
              int val = (s.charAt(i) + prefix[i]);
              val = val - (int)'a';
              val = val >= 26 ? (val % 26) + 'a' : val + 'a';
              toAppend = (char)(val);
            }
            else{
              break;
            }
            res.append(toAppend);
        }
      
      return res.toString();
    } 
}