class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        
        int i=0,j=0,max=Integer.MIN_VALUE;
        Map<Character,Integer> ctMap = new HashMap<Character,Integer>();
		/*
		    Take any window and ask the question : Which character I should not replace??
			Eg : TTFT (k=1), In this string, T should not be replaced as it is already the most frequent.
			     Replace F as 1 (k = 1) replacements are allowed.
				 If for suppose, 2 replacements were needed in this string, that window would have been invalid.
				 In that case, start incrementing the left pointer (i), until the below inequality becomes invalid.
			For a window to be valid, (window size - no. of most freq. elements) < k (no. of replacements allowed)
		*/
        while(j<answerKey.length()){
            ctMap.put(answerKey.charAt(j),ctMap.getOrDefault(answerKey.charAt(j),0)+1);
            
            while( (j-i+1) - Collections.max(ctMap.values()) > k){
                char temp = answerKey.charAt(i);
                ctMap.put(temp,ctMap.get(temp)-1);
                i++;
            }
            
            max = Math.max(max,j-i+1);
            j++;
        }
        
        return max;
    }
}