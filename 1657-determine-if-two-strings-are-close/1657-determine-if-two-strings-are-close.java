class Solution {
    public boolean closeStrings(String word1, String word2) {
        if(word1.length()!=word2.length()){
            return false;
        }
        HashMap<Character,Integer> map = new HashMap<>();
        for(char ch:word1.toCharArray()){
            map.put(ch,map.getOrDefault(ch,0)+1);
        }
        HashMap<Character,Integer> map2 = new HashMap<>();
        for(char ch:word2.toCharArray()){
            if(!map.containsKey(ch)){
                return false;
            }
            map2.put(ch,map2.getOrDefault(ch,0)+1);
        }
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        for(char ch:map.keySet()){
            l1.add(map.get(ch));
        }
        for(char ch:map2.keySet()){
            l2.add(map2.get(ch));
        }
        Collections.sort(l1);
        Collections.sort(l2);
        
        return l1.equals(l2);
    }
}