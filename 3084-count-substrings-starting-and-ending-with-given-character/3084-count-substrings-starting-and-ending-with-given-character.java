class Solution {
    public long countSubstrings(String s, char c) {
        long c_count = 0,ans = 0;;   // Initilize long variable c_count and ans as 0.
        for(int i=s.length()-1;i>=0;i--){   // Loop through the string s and check if the ith character is equal to c, if so then increment c_count by 1 and add c_count to the numerator.
            if(s.charAt(i)==c){
                c_count++;
                ans = ans + c_count;
            }
        }
        return ans;   // return ans.
    }
}