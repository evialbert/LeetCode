class Solution {
    public int minimumPushes(String word) {
        int n = word.length();
        int[] freq = new int[26];
        for (char c : word.toCharArray())
            freq[c - 'a']++;
        Arrays.sort(freq);
        List<Integer> sortedList = new ArrayList<>();
        for (int i = 25; i >= 0; i--) {
            if (freq[i] == 0)
                break;
            sortedList.add(freq[i]);
        }
        int count = 0, sum = 0;
        for (int i = 0; i < sortedList.size(); i++) {
            count++;
            int mul = (count > 24 ? 4 : (count > 16 ? 3 : (count > 8 ? 2 : 1)));
            sum += sortedList.get(i) * mul;
        }
        return sum;
    }
}