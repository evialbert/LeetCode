class Solution {
    public String reversePrefix(String word, char ch) {
        int idx=word.indexOf(ch);
        if(idx==-1)
            return word;
        return solve(word,0,idx);
    }
    String solve(String word,int i,int j)
    {
        char str[]=word.toCharArray();
        while(i<j)
        {
            char c=str[i];
            str[i++]=str[j];
            str[j--]=c;
        }
        return new String(str);
    }
    
}