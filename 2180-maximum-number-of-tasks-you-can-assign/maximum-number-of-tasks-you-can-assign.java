class Solution {
    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        int m = tasks.length, n = workers.length;

        // Sort both arrays to enable greedy matching
        Arrays.sort(tasks);
        Arrays.sort(workers);

        int l = 0, r = Math.min(m, n);  // We can assign at most min(m, n) tasks

        // Binary search to find the maximum number of tasks that can be assigned
        while (l <= r) {
            int mid = l + r >> 1;  // Try to assign 'mid' tasks

            // Start checking from the strongest 'mid' workers
            if (check(tasks, workers, pills, strength, mid, n - mid)) {
                l = mid + 1;  // Try to assign more tasks
            } else {
                r = mid - 1;  // Try fewer tasks
            }
        }

        return r;  // r is the maximum number of assignable tasks
    }

    // Helper function to check if 'mid' tasks can be assigned to the top 'mid' workers
    public boolean check(int[] tasks, int[] workers, int pills, int strength, int mid, int start) {
        int[] que = new int[mid];  // Temporary queue to hold tasks that can be handled with pills
        int write = 0, read = 0;

        for (int i = 0, j = 0; i < mid; i++) {
            int curStrength = workers[start + i];  // Current worker's strength

            if (read == write) {  // Queue is empty
                if (curStrength >= tasks[j]) {
                    // Worker can do the task without a pill
                    j++;
                    continue;
                }

                // Need a pill
                if (pills == 0) return false;

                curStrength += strength;
                pills--;

                // Push all tasks this worker can now handle into the queue
                while (j < mid && curStrength >= tasks[j]) {
                    que[write++] = tasks[j++];
                }

                if (read == write) return false;  // Still no tasks match

                write--;  // Assign the hardest task to this worker
            } else {
                // Queue has pending tasks that can be handled with a pill
                if (curStrength >= que[read]) {
                    read++;  // Worker can handle this queued task
                    continue;
                }

                // Need a pill
                if (pills == 0) return false;

                curStrength += strength;
                pills--;

                // Push new doable tasks into the queue
                while (j < mid && curStrength >= tasks[j]) {
                    que[write++] = tasks[j++];
                }

                write--;  // Assign the hardest task to this worker
            }
        }

        // If all queued tasks are handled, return true
        return read == write;
    }
}