// Time complexity: O(N1*N2), n1 is length of text1 and n2 is of text2
// Space complexity: O(N1*N2);
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n1 = text1.length(), n2 = text2.length();
//         make a 2d array to store the result for each lenght of 2 strings in a bottom up fashion, we have taken a 2d array because two dimensions i.e. length of text1 and length of text2 would be changing
        int lcs[][] = new int[n1+1][n2+1];
        for(int indx1 = 1; indx1<=n1; indx1++){
            for(int indx2 = 1; indx2 <= n2; indx2++){
//                 if characters at the current indicies in both string are matching then take one prev len value from both strings
                if(text1.charAt(indx1-1) == text2.charAt(indx2-1)){
                    lcs[indx1][indx2] = lcs[indx1-1][indx2-1]+1;
                }else{
// if they donot match then take one prev len from first string and one prev len from second string and take max out of them                    
                    lcs[indx1][indx2] = Math.max(lcs[indx1][indx2-1], lcs[indx1-1][indx2]);
                }
            }
        }
//         return the bottom and right most cell of the 2d array as answer
        return lcs[n1][n2];
    }
}