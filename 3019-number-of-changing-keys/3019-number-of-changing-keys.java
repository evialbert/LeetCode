class Solution {
    public int countKeyChanges(String s) {
        
        char prev=Character.toLowerCase(s.charAt(0));
        int cnt=0;
        for(int i=1;i<s.length();i++)
        {
            char ch=Character.toLowerCase(s.charAt(i));
            if(prev!=ch){
                cnt++;
            }
            prev=ch;
        }
        return cnt;
    }
}