class Solution {
    public int leastInterval(char[] tasks, int n) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> Integer.compare(b,a));
        HashMap<Character,Integer> map = new HashMap<>();
        for(char t:tasks)
            map.put(t,map.getOrDefault(t,0)+1);
        for(int i:map.values())
            pq.offer(i);
        int res = 0;
        while(!pq.isEmpty()){
            int er = pq.remove();
            res+=1;
            if(er == 1)
                continue;
            Stack<Integer> s = new Stack<>();
            int i=0;
            for(i=1;i<=n && !pq.isEmpty();i++){
                if(pq.peek() > 1)
                    s.push(pq.remove()-1);
                else
                    pq.remove();
            }
            while(s.size()!=0)
                pq.offer(s.pop());
            pq.offer(er-1);
            res += n;
        }
        return res;
    }
}