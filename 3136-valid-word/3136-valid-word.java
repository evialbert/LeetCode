class Solution {
    public boolean isValid(String word) {
        if(word.length()<3)return false;
        boolean all = true;
        boolean consonent=false;
        boolean vovel =false;
        
        for (char c: word.toCharArray()){
            if(c>=48 && c<=57)continue;
            if(c==65 ||c==97 ||c==69 ||c==101 ||c==73||c==105 ||c==79 ||c==111 ||c==85 ||c==117 ){
                vovel=true;
                continue;
            }
            if(((c>=97 && c<=122)|| (c>=65 && c<=90)) && !(c==65 ||c==97 ||c==69 ||c==101 ||c==73||c==105 ||c==79 ||c==111 ||c==85 ||c==117 )){
                consonent=true;
                continue;
            }
            all=false;
        }
        return all&&consonent&&vovel;
        
    }
}