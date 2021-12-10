class Solution {
    public void prepareLPS(String pat, int []lps){
        lps[0] = 0;
        int len = 0;
        int i=1;
        while(i<pat.length()){
            if(pat.charAt(i)==pat.charAt(len)){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                    
                }else{
                    lps[i] = len;
                    i++;
                    
                }
            }
            
        }
    
    }
    
    public String longestPrefix(String s) {
        int []lps = new int[s.length()];
        prepareLPS(s, lps);
        return s.substring(0,lps[s.length()-1]);
        
        
    }
} 