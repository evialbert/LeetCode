class Solution {
 public int[] assignTasks(int[] servers, int[] tasks){
        int[] resolution = new int[tasks.length];
        int[] tmp;

        // Stores [Weight, Index] of servers
        PriorityQueue<int[]> idle = new PriorityQueue<>((a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

        // Stores [Idle-Time, Index] of servers
        PriorityQueue<int[]> busy = new PriorityQueue<>((a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

        // Process time of available tasks
        Deque<Integer> queue = new ArrayDeque<>();

        for (int i = 0; i < servers.length; i++) {
            idle.add(new int[]{servers[i], i});
        }

        int t = 0, processedTaskI = 0, reachedTaskI = 0;
        while (processedTaskI < tasks.length){
            // Push all tasks to the queue
            while (reachedTaskI < t && reachedTaskI < tasks.length){
                queue.push(tasks[reachedTaskI++]);
            }

            // Fetch all newly idle servers
            while (!busy.isEmpty() && busy.peek()[0] <= t){
                tmp = busy.poll();
                idle.add(new int[]{servers[tmp[1]], tmp[1]});
            }

            // Assign tasks to servers
            while (!idle.isEmpty() && !queue.isEmpty()){
                tmp = idle.remove();
                busy.add(new int[]{t + queue.removeLast(), tmp[1]});
                resolution[processedTaskI++] = tmp[1];
            }

            if(idle.isEmpty() && !busy.isEmpty()){
                t = busy.peek()[0];
            } else
                t++;
        }

        return resolution;
    }
}