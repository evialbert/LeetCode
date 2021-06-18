class Solution {
    public int maximumRemovals(String s, String p, int[] removable) {
        int low = 0;
        int high = removable.length-1;
        int ans = 0;
        
        while(low<=high){
            int mid = low +(high-low)/2;
            HashSet<Integer> removed = new HashSet(); // set of removed indices
            for(int i =0;i<=mid;i++) removed.add(removable[i]);
            if(isSubsequence(s,p,removed)){
                ans = mid+1; // because 0 based indexing
                low = mid+1; // can we remove more characters ? 
            }else high = mid-1; // cant remove more characters fall back a little 
        }
        
        return ans;
    }
    // function to check if p is subsequence of s after removing
    // some characters in s
    private boolean isSubsequence(String s , String p , HashSet<Integer> removed){ 
        int i =0;
        int j = 0;
        
        while(i<s.length()&&j<p.length()){
            if(!removed.contains(i)){
                if(s.charAt(i)==p.charAt(j)){
                    j++;                    
                }
            }
             i++;
        }
        
        return j==p.length();
    }
}