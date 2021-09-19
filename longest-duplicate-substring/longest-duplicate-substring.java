class Solution {
    public String longestDupSubstring(String S) {
        String ans = "";
        
        int left = 1;
        int right = S.length()-1;
        
        while(left <= right){
            int m = left + (right - left)/2;
            
            String dup = getDup(m,S);
            
            if(dup != null){
                ans = dup;
                left = m+1;
            }else{
                right = m-1;
            }
        }
        
        return ans;
    }
    
    private String getDup(int size, String s){
        long H = hash(s.substring(0,size));
		
        HashSet<Long> set = new HashSet();
        set.add(H);

        long pow = 1;
        for(int i=1;i<size;i++)
            pow = (pow * 31);
        
		int n = s.length();
        for(int i=size;i < n;i++){
            H = nextHash(pow, H, s.charAt(i-size), s.charAt(i));
            if(!set.add(H)){
                return s.substring(i-size+1, i+1);
            }
        }
        
        return null;
    }
    
    private long hash(String s){
        long h = 0;
        long a = 1;
        
		int n = s.length();
        for(int k=n;k>=1;k--){
            char ch = s.charAt(k-1);
            h += (ch - 'a' + 1) * a;
            a = (a*31);
        }
        
        return h;
    }
    
    private long nextHash(long pow,long hash,char left,char right){
        return (hash - (left - 'a' + 1) * pow) * 31 + (right - 'a' + 1);
    }
}
