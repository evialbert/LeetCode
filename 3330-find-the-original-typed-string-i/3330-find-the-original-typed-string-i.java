class Solution {
    public int possibleStringCount(String word) {
        int c=0;
        for(int i=0;i<word.length()-1;i++)
        {
            if(word.charAt(i)==word.charAt(i+1))
            c++;
        }
        return c+1;
    }
}