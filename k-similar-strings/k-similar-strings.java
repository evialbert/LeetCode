class Solution {
    public int kSimilarity(String s1, String s2) {
        char []arr1 = s1.toCharArray();
        char []arr2 = s2.toCharArray();
        return kSimilarity(arr1, arr2, 0 ,0);
    }
    
    public int kSimilarity(char arr1[], char[] arr2, int index, int depth) {
        
        int out = depth;
        for(int i = index ; i < arr1.length ; i++) {
            if(arr1[i] != arr2[i]) {
                int res = Integer.MAX_VALUE;
                for(int j = i + 1; j < arr2.length ; j++) {
                    if(arr1[i] == arr2[j] && arr1[j] != arr2[j]){
                        char swapped[] = swap(arr2, i , j);
						// Checking for Candidates 
                        int dist = kSimilarity(arr1, swapped, i + 1, depth + 1);
                        res = Math.min(res, dist);
                    }
                }
                return Math.max(res, out);
            }
        }
        return out;
    }
    
    public char[] swap(char arr[], int i, int j) {
        char[] s = arr.clone();
        char back = s[i];
        s[i] = s[j];
        s[j] = back;
        return s;
    }
}