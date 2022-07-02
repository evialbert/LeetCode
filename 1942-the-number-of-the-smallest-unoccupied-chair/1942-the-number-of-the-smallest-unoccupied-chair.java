class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        PriorityQueue<int[]> friends = new PriorityQueue<>((a,b) -> a[0] - b[0]);
        
        HashMap<Integer, List<Integer>> leaving_chair = new HashMap<>();
        
        int index = 0;
        
        for(int[] time: times){
            friends.offer(new int[]{time[0], time[1], index++});
            
            leaving_chair.putIfAbsent(time[1], new ArrayList<>());
        }
        
        PriorityQueue<Integer> chairs = new PriorityQueue<>();
        
        int newChair = 0;
        
        int time = friends.peek()[0];
        
        while(!friends.isEmpty()){
            if(leaving_chair.containsKey(time)){
                for(int i: leaving_chair.get(time))
                    chairs.offer(i);
            }
            if(friends.peek()[0] == time){
                int friend = friends.peek()[2];
                int arrival = friends.peek()[0];
                int leaving = friends.poll()[1];

                int chair = 0;

                if(!chairs.isEmpty())
                    chair = chairs.poll();
                else
                    chair = newChair++;

                leaving_chair.get(leaving).add(chair);

                if(friend == targetFriend)
                    return chair;
            }
            time++;
        }
        return 0;
    }
}