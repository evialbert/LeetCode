class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] freq = new int[26];
        TreeSet<Character> set = new TreeSet<>();

        // Count the frequency of characters and populate the TreeSet with unique characters.
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            freq[ch - 'a']++;
            set.add(ch);
        }

        StringBuilder sb = new StringBuilder();
        int count = 0;

        // Iterate through the characters in descending order and repeat each character up to the repeatLimit.
        while (!set.isEmpty()) {
            char top = set.pollLast();
            count = 1;

            while (count <= repeatLimit && freq[top - 'a'] > 0) {
                sb.append(top);
                count++;
                freq[top - 'a']--;
            }

            if (!set.isEmpty() && freq[top - 'a'] > 0) {
                count = 0;
                char temp = set.pollLast();
                sb.append(temp);
                set.add(top);
                freq[temp - 'a']--;

                if (freq[temp - 'a'] != 0)
                    set.add(temp);
            } else if (!set.isEmpty() && freq[top - 'a'] == 0) {
                count = 0;
            }
        }

        return sb.toString();
    }
}
