class Solution {
    public boolean is_ok(String s,int len){
        int n=s.length();
        int first_fre[]=new int[26];
        for(int i=0;i<len;i++){
            char ch=s.charAt(i);
            first_fre[ch-'a']++;
        }
        for(int i=len;i<n;i+=len){
            int curr_fre[]=new int[26];
            for(int j=i;j<i+len;j++){
                char c=s.charAt(j);
                curr_fre[c-'a']++;
            }
            for(int k=0;k<26;k++){
                if(curr_fre[k]!=first_fre[k]){
                    return false;
                }
            }
        }
        return true;
    }
    public int minAnagramLength(String s) {
        int n=s.length();
        for(int len=1;len<=n;len++){
            if(n%len==0 && is_ok(s,len)){
                return len;
            }
        }
        return -1;
    }
}