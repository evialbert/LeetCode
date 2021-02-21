class Solution {
	public boolean validPalindrome(String s) {
		int i = 0;
		int j = s.length() - 1;
		while (i < j) {
			if(s.charAt(i) == s.charAt(j)) {
				i++;
				j--;
			}
			else {
				return chk(s, i + 1, j) || chk(s, i, j -1);
			}
		}
		return true;
	}

	public boolean chk(String s, int i, int j) {
		while (i < j) {
			if (s.charAt(i) == s.charAt(j)) {
				i++;
				j--;
			}
			else return false;
		}
		return true;
	}
}