class Solution {
    
    public boolean isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    //returns true if the word is satistifed with first and last character as vowels
    public boolean isVowelString(String word){
        int length = word.length();
        if(length == 0) return false;
        if((isVowel(word.charAt(0)) && (isVowel(word.charAt(length-1))))){
            return true;
        }
        return false;
    }
    //returns the number of strings valid in a range(left to right)(inclusive)
    public int noOfStringsValid(int li,int ri,int prefix[]){
        if(li == 0){
            return prefix[ri];
        }
        return prefix[ri] - prefix[li-1];
    }
    //main function
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length;
        int prefix[] = new int[n];
        int sum = 0;
        for(int i=0;i<n;i++){
            if(isVowelString(words[i]) == true){
                sum++;
            }
            prefix[i] = sum;
        }
        int queriesLength = queries.length;
        int ans[] = new int[queriesLength];
        for(int i=0;i<queriesLength;i++){
            int li = queries[i][0], ri = queries[i][1];
            ans[i] = noOfStringsValid(li,ri,prefix);
        }
        return ans;
    }
    
}