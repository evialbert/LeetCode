class Solution {
    private static final Object[] NUMS = new Object[]{
            "six", 'x', 6,
            "eight", 'g', 8,
            "three", 'h', 3,
            "two", 'w', 2,
            "four", 'u', 4,
            "zero", 'z', 0,
            "one", 'o', 1,
            "five", 'f', 5,
            "seven", 's', 7,
            "nine", 'i', 9};

    public String originalDigits(final String s) {
        final int[] map = new int[26];
        for (char ch : s.toCharArray()) map[ch-'a']++;
        final int[] res = new int[10];
        for (int i = 0; i < NUMS.length; i+= 3) {
            String word = (String) NUMS[i];
            char ch = (char) NUMS[i+1];
            int num = (int) NUMS[i+2];
            int times = map[ch-'a'];
            if (times > 0) {
                for (char c : word.toCharArray()) map[c-'a']-= times;
                res[num] = times;
            }
        }

        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++)
            while (res[i]-- > 0) sb.append(i);
        return sb.toString();
    }
}