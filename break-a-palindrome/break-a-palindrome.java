class Solution {
   public String breakPalindrome(String palindrome) {
    int i = 0, len = palindrome.length();
    StringBuilder sb1 = new StringBuilder();
    if (len == 1)
        return "";
    while(i<len/2)
    {
        if(palindrome.charAt(i)!='a')
        {
            sb1.append(palindrome);
            sb1.replace(i,i+1,"a");
            break;
        }
            i++;
    }
    if (i == len/2)
    {
        sb1.append(palindrome);
        sb1.replace(len-1,len,"b");
    }
        
    return sb1.toString();
}
}