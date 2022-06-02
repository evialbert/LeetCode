class Solution {
    public String largestMerge(String word1, String word2) {
     if(word1.length() == 0 && word2.length() == 0) return "";
    if(word1.length() == 0) return word2;
    if(word2.length() == 0) return word1;
    
    if(word1.compareTo(word2) >= 0){
        return word1.substring(0, 1) + largestMerge(word1.substring(1), word2);
    }else{
        return word2.substring(0, 1) + largestMerge(word1, word2.substring(1));
    }
}   
    
}