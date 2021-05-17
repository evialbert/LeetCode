class Solution {
    
    int maxCombination = 1;
    int K;
    int N;
    String res;
    public boolean crackSafeHelper(String prefix, Set<String> allCombs) {
        if (prefix.length() >= N 
			&& allCombs.contains(prefix.substring(prefix.length() - N))) {
            return false;
        }
        if (prefix.length() >= N) allCombs.add(prefix.substring(prefix.length() - N));
        if (allCombs.size() >= maxCombination) {
            res = prefix;
            return true;
        }
        
        for (int i = 0; i < K; i++) {
            if(crackSafeHelper(prefix + String.valueOf(i), allCombs)) return true;
        }
        if (prefix.length() >= N) allCombs.remove(prefix.substring(prefix.length() - N));
        return false;
    }
    public String crackSafe(int n, int k) {
        // minimize the overlap that covers
        // all the combination with length of n picked from number [0, k - 1]
        K = k;
        N = n;
        for (int i = 0; i < N; i++) {
            maxCombination *= K;
        }
        crackSafeHelper("", new HashSet<>());
        return res;
    }
}