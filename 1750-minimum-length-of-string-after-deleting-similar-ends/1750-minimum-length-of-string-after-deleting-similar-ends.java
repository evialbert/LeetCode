class Solution {
    public int minimumLength(String s) {
        int x=0;
        int ans=s.length();
    for(int i=0, j=s.length()-1; i<j; i++, j--){
        int ch=s.charAt(i);
        while(ch==s.charAt(i)&&i<j){
            i++;
            x++;
        }
        i--;
        int sh=s.charAt(j);
        while(sh==s.charAt(j)&&i<j){
            j--;
            x++;
        }
        j++;
        if(ch==sh){
            ans=ans-x;
        }
        else break;
        x=0;
    }
        return ans;
    }
}