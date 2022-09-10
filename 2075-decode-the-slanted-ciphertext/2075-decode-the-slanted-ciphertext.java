class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        char[][] ch = new char[rows][encodedText.length()/rows];
        int index = 0;
        for(int i=0;i<ch.length;i++){
            for(int j=0;j<ch[0].length;j++){
                ch[i][j]= encodedText.charAt(index++);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int gap =0;gap<ch[0].length;gap++){
            for(int i=0,j=gap;i<rows && j<encodedText.length()/rows;i++,j++){
                sb.append(ch[i][j]);
            }
        }
        while(sb.length()>0 && sb.charAt(sb.length()-1) == ' '){
            sb.deleteCharAt(sb.length()-1);
        }
        return sb.toString();
    }
}