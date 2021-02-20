public class Solution {
    public char findTheDifference(String s, String t) {
        char[] s1=s.toCharArray();
        int sum=0;
        for(int i=0;i<s1.length;i++){
            sum+=s1[i];
        }
        char[] s2=t.toCharArray();
        int sum1=0;
        for(int i=0;i<s2.length;i++){
            sum1+=s2[i];
        }
        int cha=sum1-sum-97;
        return (char)('a'+cha);
    }
}