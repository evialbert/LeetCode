class Solution {

    public String mostCommonWord(String paragraph, String[] banned) {

        Map<String, Integer> map = new HashMap<>();

        int start = 0, end = 0;

        int len = paragraph.length();

        while (end < len) {

            while (end < len && Character.isLetter(paragraph.charAt(end))) {

                end++;

            }

            String cur = paragraph.substring(start, end).toLowerCase();

            map.put(cur, map.getOrDefault(cur, 0) + 1);

            

            if (end < len) end++;

            start = end;

        }

        String ans = "";

        int ansFreq = 0;

        for (String s : banned) {

            map.remove(s);

        }

        for (String key : map.keySet()) {

            if (key.length() > 0 && map.get(key) > ansFreq) {

                ans = key;

                ansFreq = map.get(key);

            }

        }

        return ans;
    }
}