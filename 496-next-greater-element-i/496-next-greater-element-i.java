class Solution {
	public int[] nextGreaterElement(int[] nums1, int[] nums2) {
		Stack<Integer> s = new Stack<>();
		// ele-ngr
		HashMap<Integer, Integer> hm = new HashMap<>();

		for (int i = nums2.length - 1; i >= 0; i--) {
			if (s.isEmpty()) {
				hm.put(nums2[i], -1);
			} else if (!s.isEmpty() && s.peek() > nums2[i]) {
				hm.put(nums2[i], s.peek());
			} else if (!s.isEmpty() && s.peek() <= nums2[i]) {
				while (!s.isEmpty() && s.peek() <= nums2[i]) {
					s.pop();
				}
				if (!s.isEmpty())
					hm.put(nums2[i], s.peek());
				else
					hm.put(nums2[i], -1);
			}
			s.push(nums2[i]);
		}
		int[] res = new int[nums1.length];
		for (int i = 0; i < nums1.length; i++) {
			int val = hm.get(nums1[i]);
			res[i] = val;
		}
		return res;

	}
}