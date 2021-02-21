class Solution {
    public boolean judgeCircle(String moves) {
        int horizontal = 0;
        int vertical = 0;
        
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('U', 1);
        map.put('D', -1);
        map.put('L', 1);
        map.put('R', -1);
        
        for (Character c: moves.toCharArray()) {
            if (c == 'U' || c == 'D') {
                horizontal += map.get(c);
            } else {
                vertical += map.get(c);
            }
        }
        
        return horizontal == 0 && vertical == 0;
    }
}