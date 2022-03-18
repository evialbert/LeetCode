class Solution {
    public boolean checkPalindromeFormation(String a, String b) {
        return isPalindrome(a, b) || isPalindrome(b, a);
    }
    
    public boolean isPalindrome(String a, String b) {
        int n = a.length();
        int i = 0;
        while(i < n && a.charAt(i) == b.charAt(n-i-1)){
            i++;
        }
        if(i >= (n+1) / 2){
            return true;
        }
        int l = i;
        int r = n-i-1;
        boolean judegeA = true;
        boolean judegeB = true;
        while(l <= r){
            if(a.charAt(l) != a.charAt(r)){
                judegeA = false;
            }
            if(b.charAt(l) != b.charAt(r)){
                judegeB = false;
            }
            l++;
            r--;
        }
        return judegeA || judegeB;
    }
}