class Solution {
    public int mostBooked(int n, int[][] meetings) {
        int meetingCount[] = new int[n];
        PriorityQueue<Integer> unused = new PriorityQueue<>();
        PriorityQueue<long[]> used = new PriorityQueue<>(
            (a, b) -> a[0] != b[0] ? Long.compare(a[0], b[0]) : Long.compare(a[1], b[1])
        );
        for(int i = 0;i < n;i++){
            unused.offer(i);
        }
        Arrays.sort(meetings, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));
        for(int meeting[] : meetings){
            int start = meeting[0];
            int end = meeting[1];
            while(!used.isEmpty() && used.peek()[0] <= start){
                int room = (int)used.poll()[1];
                unused.offer(room);
            }
            if(!unused.isEmpty()){
                int room = unused.poll();
                used.offer(new long[]{end, room});
                meetingCount[room]++;
            }else{
                long roomAvalTime = used.peek()[0];
                int room = (int)used.poll()[1];
                used.offer(new long[]{roomAvalTime + end - start, room});
                meetingCount[room]++;
            }
        }
        int maxCount = 0;
        int maxRoom = 0;
        for(int i = 0;i < n;i++){
            if(meetingCount[i] > maxCount){
                maxCount = meetingCount[i];
                maxRoom = i;
            }
        }
        return maxRoom;
    }
}