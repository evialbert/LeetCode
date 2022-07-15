class Solution {
   public int minTimeToType(String word) {
    int res=word.length();
    if(word.charAt(0)!='a')word="a"+word;
    for(int i=0;i<word.length()-1;i++)
    {
        int n1=Math.abs(((word.charAt(i)-'a')+1)-((word.charAt(i+1)-'a')+1));
        int n2=Math.abs(26-n1);            
        res+=Math.min(n1,n2);
    }
    return res;
 }
}
