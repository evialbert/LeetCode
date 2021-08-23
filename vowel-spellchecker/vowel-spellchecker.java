class Solution {

    public String[] spellchecker(String[] words, String[] queries) {
        Map<String, Integer> strictMap = new HashMap<>();
        Map<String, Integer> capMap = new HashMap<>();
        Map<String, Integer> vowelMap = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            final String word = words[i];
            if (!strictMap.containsKey(word)) strictMap.put(word, i);
            if (!capMap.containsKey(getCap(word))) capMap.put(getCap(word), i);
            if (!vowelMap.containsKey(deVowel(word))) vowelMap.put(deVowel(word), i);
        }
        String[] res = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            final String query = queries[i];
            int index = -1;
            if(strictMap.containsKey(query)) index = strictMap.get(query);
            else if(capMap.containsKey(getCap(query))) index = capMap.get(getCap(query));
            else if(vowelMap.containsKey(deVowel(query))) index = vowelMap.get(deVowel(query));
            res[i]  = index >= 0 ? words[index]: "";
        }
        return res;
    }

    private String deVowel(String word) {
        return word.toLowerCase().replaceAll("[aeiou]", "a");
    }

    private String getCap(String word) {
        return Character.toUpperCase(word.charAt(0)) + word.substring(1).toLowerCase();
    }
}