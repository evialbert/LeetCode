class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length())
            return false;
        HashMap<Character, Character> stot = new HashMap<Character, Character>();
        HashMap<Character, Character> ttos = new HashMap<Character, Character>();
        for (int i = 0; i < s.length(); i ++){ 
            if (stot.containsKey(s.charAt(i))){
                if (stot.get(s.charAt(i)) != t.charAt(i)){
                    return false;
                }
            }
            if (ttos.containsKey(t.charAt(i))){
                if (ttos.get(t.charAt(i)) != s.charAt(i)){
                    return false;
                }
            }
            stot.put(s.charAt(i), t.charAt(i));
            ttos.put(t.charAt(i), s.charAt(i));
        }
        return true;
    }
}