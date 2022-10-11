class Solution {
   public int wordCount(String[] startWords, String[] targetWords) {
        Set<Integer> startSet = new HashSet<>();
        for(String word : startWords){
           startSet.add(toInt(word));
        }
        int ans = 0;
        for(String word : targetWords){
            int num = toInt(word);
            for(int i=0; i<26; i++){
                if((num & (1<<(i))) > 0){
                    int temp = num - (1<<(i));
                    if(startSet.contains(temp)){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
    
    public int toInt(String s){
        int ret = 0;
        for(char c : s.toCharArray()){
            ret += (1<<(c-'a'));
        }
        return ret;
    }
}