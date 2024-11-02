class Solution {
    public boolean isCircularSentence(String sentence) {
        int n = sentence.length();
        if(sentence.charAt(0) != sentence.charAt(n - 1)) return false;
        for(int i =0;i < n; i++){
            if(sentence.charAt(i) == ' ' && sentence.charAt(i - 1) != sentence.charAt(i + 1)) return false;
        }
        return true;         
    }
}