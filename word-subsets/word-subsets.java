class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        List<String> result = new ArrayList<String>();
        
        int maximumWordFrequency[] = new int[26];
        
        for(int i=0; i<B.length; i++){
            String currentWord = B[i];
            int characterFrequency[] = getCharacterFrequencyInWord(currentWord);
            for(int j=0; j<26; j++){
                maximumWordFrequency[j]=Math.max(characterFrequency[j], maximumWordFrequency[j]);
            } 
        }
        
        
        for(int i=0; i<A.length; i++){
            String currentWord= A[i];
            int characterCount[] = getCharacterFrequencyInWord(currentWord);
            boolean valid = true;
            for(int j=0; j<26; j++){
                if(maximumWordFrequency[j]>characterCount[j]){
                    valid=false;
                    break;
                  }
            }
            if(valid)
            result.add(currentWord);
        }
        return result;
    }
    

    public int[] getCharacterFrequencyInWord(String s){
        int result[] = new int[26];
        for(char c : s.toCharArray()){
            result[c-'a']++;
        }
        return result;
    }
}