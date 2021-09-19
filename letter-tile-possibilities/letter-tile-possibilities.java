class Solution {
    static int  count = 0;
   public int numTilePossibilities(String tiles) {
	        count = 0;
	        Map<Character, Integer> map = new HashMap<Character, Integer>();
	        for (char c: tiles.toCharArray()) {
	        	map.put(c, map.getOrDefault(c, 0)+1);
	        }
	        count(map, 0, tiles.length());
	        return count-1;
	    }
	    public void count(Map<Character, Integer> map, int cs, int ts) {
	    	
	    	if(cs<=ts) {
	    		count++;
				// Here you can also print the word all combinations by passing character string in recursion
	    	}
	    	for(char c: map.keySet()) {
	    		if (map.get(c) > 0) {
	    			map.put(c, map.get(c)-1);
	    			count(map, cs+1, ts);
	    			map.put(c, map.get(c)+1); // backtrack
	    		}
	    	}
	    	
	    }
}