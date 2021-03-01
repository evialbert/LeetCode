class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        HashMap<String, Integer> map = new HashMap<>();
        List<List<Integer>> answer = new ArrayList<>();
        int index = 0;
        for(String word : words) map.put(new StringBuilder(word).reverse().toString(), index++);
        index = 0;
        for(String word : words){
            for(int i = 0; i <= word.length(); i++){
                String word1 = word.substring(0,i);
                String word2 = word.substring(i);
                if(isPalindrome(word1) && map.containsKey(word2)){
                    if(map.get(word2)!=index){
                        List<Integer> pair = new ArrayList<>();
                        pair.add(map.get(word2));
                        pair.add(index);
                        answer.add(pair);
                    }
                }
                
                if(isPalindrome(word2) && map.containsKey(word1) && word2.length() != 0){
                    if(map.get(word1) != index){
                        List<Integer> pair = new ArrayList<>();
                        pair.add(index);
                        pair.add(map.get(word1));
                        answer.add(pair);
                    }
                }
            }
            index++;
        }
        return answer;
    }
    
    private boolean isPalindrome(String word){
        int start = 0, end = word.length()-1;
        while(start < end){
            if(word.charAt(start++) != word.charAt(end--)) return false;
        }
        return true;
    }
}