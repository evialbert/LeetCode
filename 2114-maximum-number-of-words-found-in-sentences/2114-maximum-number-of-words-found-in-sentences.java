class Solution {
    public int mostWordsFound(String[] sentences) {
        int max = 0;
        for(int i=0;i<sentences.length;i++){
            if( sente(sentences[i])>max)
                max = sente(sentences[i]);
        }
        return max;
    }
    public int sente(String s){
        String str[]  =s.split(" ");
        return str.length;
    }
}