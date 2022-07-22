class Solution {
    public char findTheDifference(String s, String t) {
        char[] sc = s.toCharArray();
        char[] st = t.toCharArray();
        int sumSc = 0, sumTc = 0;
        for(char c : sc){
            sumSc += c;
        }
        for(char c : st){
            sumTc += c;
        }
        return (char) (sumTc - sumSc);
    }
}