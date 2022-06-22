class Solution {
    public String sortSentence(String s) {
        String[] strings = s.split(" ");
        String[] res = new String[strings.length];
        for (String str : strings){
            char c = str.charAt(str.length()-1);
            int key = Character.getNumericValue(c);
            res[key-1] = str.substring(0,str.length()-1);
        }
        StringBuilder sb = new StringBuilder();
        int i = 0;
        for (i = 0; i < res.length-1; i++){
            sb.append(res[i]).append(" ");
        }
        sb.append(res[i]);
        return sb.toString();
    }
}