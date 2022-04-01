class Solution {
   public int countSubstrings(String s, String t) {
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < t.length(); j++) {
				int diff = 0;
				int x = i;
				int y = j;
				while (x<s.length() && y<t.length()){
					if(s.charAt(x)!=t.charAt(y)) diff++;
					if(diff == 1) ans++;
					if(diff==2) break;
					x++;
					y++;
				}
			}
		}
		return ans;
	}
}