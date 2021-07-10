class Solution {
    public int minimumLengthEncoding(String[] words) {
        int n = words.length, ret=0;
        for(int i=0; i<n; i++)words[i] = new StringBuffer(words[i]).reverse().toString();
        Arrays.sort(words);
        for(int i=0; i<n-1; i++){
            if(words[i].length()<=words[i+1].length() && 
               words[i+1].substring(0, words[i].length()).equals(words[i]))continue;
            ret+=words[i].length()+1;
        }
        return ret+words[n-1].length()+1;
    }
}