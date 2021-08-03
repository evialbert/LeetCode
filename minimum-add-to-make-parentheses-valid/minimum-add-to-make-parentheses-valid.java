class Solution {
public int minAddToMakeValid(String s) {
    int countleft=0;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s.charAt(i)=='(')
            ++countleft;
        else{
            if(countleft<=0)
                count++;
           else{
            --countleft;
           }}}
        return count+countleft;
    }
}