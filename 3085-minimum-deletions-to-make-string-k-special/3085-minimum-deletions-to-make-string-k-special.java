class Solution {
    public int minimumDeletions(String word, int k) {
        char c[]=word.toCharArray();
        int[] freq=new int[26];
        int n=word.length();
        for(int i=0;i<n;i++){
            freq[c[i]-'a']++;
        }
        int min=100000;
        for(int i=0;i<=n;i++){
            int count=0;
            for(int j=0;j<26;j++){
                if(freq[j]==0)
                    continue;
                if(freq[j]>i+k){
                    count+=freq[j]-i-k;
                }
                else if(freq[j]<i){
                    count+=freq[j];
                }
            }
            min=Math.min(min,count);
        }
        
        return min;
    }
}