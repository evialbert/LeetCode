//Java easy recursive
class Solution {
    public String makeGood(String s) {
        if(s.length()==0|| s.length()==1){
            return s;
        }
        for(int i=0;i<s.length()-1;i++){
            char ch=s.charAt(i);
            char ch1=s.charAt(i+1);
            if((ch==(ch1+32)) || (ch+32==ch1)){
                return makeGood(s.substring(0,i)+s.substring(i+2)); 
            }
        }
        return s; 
        }
}