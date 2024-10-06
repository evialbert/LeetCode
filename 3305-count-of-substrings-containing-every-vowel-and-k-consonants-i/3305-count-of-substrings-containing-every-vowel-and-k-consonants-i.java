class Solution {
    public int countOfSubstrings(String word, int k) {
        int n = word.length();
        Map<Character, Integer> set = new HashMap();
        int ans = 0;
        for (int i=0 ; i<n ; i++){
            int r= i;
            int count = 0;
            set.clear();
            while (r<n){
                if (isConsonants(word.charAt(r))){
                    count++;
                }
                else {
                    set.put(word.charAt(r), set.getOrDefault(word.charAt(r) , 0) + 1);
                }

                if (count == k && set.size() == 5){
                    ans++;
                }
                r++;
            }
        }
        return ans;
    }
    
    public boolean isConsonants(Character ch){
        return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
    }
}