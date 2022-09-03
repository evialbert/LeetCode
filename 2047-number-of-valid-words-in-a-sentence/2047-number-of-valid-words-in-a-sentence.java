class Solution {
    public int countValidWords(String sentence) {
        String[]sent=sentence.split(" ");
        int res=0;
        for(String s: sent){
            if(s.length()>0 && check(s)) res++;
        }
        
        return res;
    }
    
    public boolean check(String s){
        int hyp=0;
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(Character.isDigit(c)) return false;
            else if(c=='-'){
                if(i==0 || i==s.length()-1 || !Character.isLetter(s.charAt(i-1)) || !Character.isLetter(s.charAt(i+1)) || hyp>0) return false;
                hyp++;
            }else if(c=='!' || c=='.' || c==','){
                if(i!=s.length()-1) return false;
            }
        }
        
        return true;
    }
}