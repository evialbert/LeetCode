class Solution {
    public String frequencySort(String s) {
        if (s == null || s.length() == 1) {
			return s;
		}
// map to store frequency with counter
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < s.length(); i++) {
			map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
		}

// PriorityQueue having sorted with high frequency
		PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> (b.count - a.count));

		for (Map.Entry m : map.entrySet()) {
			Pair p = new Pair((int) m.getValue(), (char) m.getKey());
			pq.add(p);
		}

		StringBuilder sb = new StringBuilder();
		while (!pq.isEmpty()) {
			Pair p = pq.remove();
			int cnt = p.count;
			while (cnt > 0) {
				sb.append(p.ch);
				cnt--;
			}
		}

		return sb.toString();
        
    }
    	static class Pair {
		int count;
		char ch;

		Pair(int count, char ch) {
			this.count = count;
			this.ch = ch;
		}
	}
}