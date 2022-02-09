class Solution {
    
    public int calc(int n){
        int x=0;
        int i=1;
        while(i<=n){
            x=(x+n-i+1)%1000000007;
            i++;
        }
        return x;
    }
    
    public int numSub(String s) {
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='1'){
                int j=i;
                while(j+1<s.length() && s.charAt(j+1)=='1'){
                    j++;
                }
                c= (c+calc(s.substring(i,j+1).length()))%1000000007;
                i=j;
            }
        }
        return c;
    }
}