class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        int[] ans = new int[n];
        Arrays.sort(deck);
        
        Deque<Integer> q = new LinkedList<>();
        q.add(deck[n-1]); // add first element
        
        for (int i = n-2; i >= 0; i--) {
            int last = q.removeLast();
            q.addFirst(last);
            q.addFirst(deck[i]);
        }
        
        int idx = 0;
        while (!q.isEmpty()) ans[idx++] = q.removeFirst();
        
        return ans;
    }
}