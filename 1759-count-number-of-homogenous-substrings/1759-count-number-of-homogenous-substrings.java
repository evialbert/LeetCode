class Solution {
    public int countHomogenous(String s) {
        char previous = s.charAt(0);
        int count = 1;
        int result = 1;
        for(int i=1;i<s.length();i++)
        {
            if(s.charAt(i)==previous)
                count++;
            else
            {
                previous = s.charAt(i);
                count = 1;
            }
            result = (result+count)%(int)(1e9 + 7);
        }
        return result;
    }
}