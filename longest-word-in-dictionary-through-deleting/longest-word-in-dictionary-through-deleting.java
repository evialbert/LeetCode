class Solution {
    public String findLongestWord(String s, List<String> list) {
        Collections.sort(list, (a, b) -> {
            if (a.length() == b.length()) {
                return a.compareTo(b);
            } else {
                return b.length() - a.length();
            }
        });
        
        for(String dic:list){
            int j=0;
            for(int i=0;i<s.length();i++){
                if(j<dic.length() && s.charAt(i)==dic.charAt(j)){
                    j++;
                }
            }
            if(j==dic.length()) return dic; 
        }
        return "";
        
    }
}