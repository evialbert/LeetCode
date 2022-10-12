class Solution {
    public String[] divideString(String s, int k, char fill) {
        while(s.length()%k!=0){

            s+=fill;
        }
        String[] str=new String[s.length()/k];
        
        int i=0;
        int j=k;
       for(int p=0;p<str.length;p++){
           str[p]=s.substring(i,j);
           i+=k;
           j+=k;
       }
        return str;
            
        
    }
}