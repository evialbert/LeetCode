class Solution {
	public boolean checkInclusion(String s1, String s2) {

		int[] arr = new int[26];
		for (char c : s1.toCharArray()) {
			arr[c - 'a'] = arr[c - 'a'] + 1;
		}

		int n = s1.length();
		int[] arr1 = new int[26];
		for (int i = 0; i < s2.length(); i++) {

			char c = s2.charAt(i);

			if (i - n >= 0) {
				arr1[s2.charAt(i - n) - 'a'] = arr1[s2.charAt(i - n) - 'a'] - 1;
			}
			arr1[c - 'a'] = arr1[c - 'a'] + 1;
			if (arr[c - 'a'] == 0)
				continue;
			if (helper(arr1, arr))
				return true;

		}

		return false;
	}

	boolean helper(int[] arr1, int[] arr) {

		for (int i = 0; i < arr.length; i++) {
			if (arr[i] != arr1[i])
				return false;
		}

		return true;
	}
}