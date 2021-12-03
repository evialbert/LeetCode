class Solution {
	Integer result = null;
	public int findTheLongestSubstring(String s) {
		int arr[] = new int[s.length()];
		int sum = 0;
		Set<Character> set = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (set.contains(c)) {
					sum = (sum & (1 << 'a'-c)) == 0 ? (sum | (1 << 'a'-c)) : (sum & ~(1 << 'a'-c));
			}
			arr[i] = sum;
		}
        
     for (int i = 0; i < s.length(); i++) {
         if(result != null && result> s.length()-i){
             break; 
         }
       for (int j = s.length()-1; j >=i; j--) {
            int e = arr[j];
			int k = (i - 1) < 0 ? 0 : arr[i - 1];
            int M=e^k;
			if (M==0) {
				this.result = result == null ? (j - i) + 1 :  Math.max(result, (j - i) + 1);
                break;
            }
       }
     }

		return result == null ? 0 : result;

	}
}