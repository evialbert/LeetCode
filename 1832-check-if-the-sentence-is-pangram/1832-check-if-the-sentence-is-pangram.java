class Solution {
   public boolean checkIfPangram(String sentence) {
    for(int ind='a'; ind<='z'; ind++){
        if(sentence.indexOf(ind)<0){
            return false;
        }
    }
    return true;
}
}