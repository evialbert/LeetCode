class Solution {
    public int numberOfSubstrings(String s) {
        int maxZeroNum = (int)Math.sqrt(s.length());
        List<Integer> zeroIndex = new ArrayList<>();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '0') {
                zeroIndex.add(i);
            }
        }
        int ans = 0;
        for (int i = 1; i <= maxZeroNum; ++i) {
            for (int j = 0; j + i - 1 < zeroIndex.size(); ++j) {
                int leftIndex = zeroIndex.get(j);
                int rightIndex = zeroIndex.get(j + i - 1);
                int beforeLeftIndex = (j == 0) ? (0) : (zeroIndex.get(j - 1) + 1);
                int afterRightIndex = j + i >= zeroIndex.size() ? s.length() : zeroIndex.get(j + i);
                for (int start = beforeLeftIndex; start <= leftIndex; start++) {
                    int oneCnt = rightIndex - start + 1 - i;
                    int rightOne = afterRightIndex - rightIndex - 1;
                    ans += (i * i > oneCnt) ? Math.max(rightOne + oneCnt - i * i + 1, 0) : (rightOne + 1);
                }
            }
        }
        for (int i = 0; i < zeroIndex.size(); ++i) {
            int oneCnt = (i == 0) ? zeroIndex.get(i):  zeroIndex.get(i) - zeroIndex.get(i - 1) - 1;
            ans += oneCnt * (oneCnt + 1) / 2;
        }
        int lastOneCnt = zeroIndex.size() > 0 ? s.length() - zeroIndex.get(zeroIndex.size() - 1) - 1 : s.length();
        ans += lastOneCnt * (lastOneCnt + 1) / 2; 
        return ans;
    }
}