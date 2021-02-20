public class Solution {
    public boolean isPerfectSquare(int num) {
        long L = 1, R = (num >> 1) + 1;
		while (L <= R) {
			long  m = L + ((R - L) >> 1);
			long  mul = m * m;
			if (mul == num) return true;
			else if (mul > num) R = m - 1;
			else L = m + 1;
		}
		return false;
    }
}