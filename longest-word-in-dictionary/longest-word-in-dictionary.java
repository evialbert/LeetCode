class Solution {
    public String longestWord(String[] words) {
        Set<String> set = new HashSet<>(Arrays.asList(words));
        int max = 0;
        String longest = "";
        List<String> list = new ArrayList<>();
        for(String w: words){
            StringBuilder sb = new StringBuilder();
            for(char c: w.toCharArray()){
                sb.append(c);
                if(set.contains(sb.toString())){
                    if(    sb.length() > max 
                       || (    sb.length() == max 
                            && sb.toString().compareTo(longest) < 0)){
                        longest = sb.toString();    
                        max = sb.length();
                    }
                }
                else break;
            }
        }
        return longest;
    }
}