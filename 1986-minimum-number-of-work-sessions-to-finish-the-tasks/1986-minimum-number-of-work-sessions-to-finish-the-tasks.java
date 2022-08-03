class Solution {
    public int minSessions(int[] tasks, int sessionTime) {
        int len = tasks.length;
        int i = 1; // minimum, all tasks can fit into 1 session
        int j = len; // maximum, each task take 1 session to finish
        
        while (i < j) {
            int m = (i + j) / 2; // try m sessions to see whether can work
            if (canFit(tasks, new int[m], sessionTime, len - 1)) {
                j = m;
            } else {
                i = m + 1;
            }
        }
        return i;
    }
    
    private boolean canFit(int[] tasks, int[] sessions, int sessionTime, int idx) {
        if (idx == -1) { // all tasks have been taken care of
            return true;
        }
        
        Set<Integer> dup = new HashSet<>();
        // now to take care of tasks[idx]
        for (int i = 0; i < sessions.length; i++) { // try each spot
            if (sessions[i] + tasks[idx] > sessionTime) { // current spot cannot fit
                continue;
            }
            if (dup.contains(sessions[i] + tasks[idx])) {
                continue;
            }
            dup.add(sessions[i] + tasks[idx]);
            
            sessions[i] += tasks[idx];
            if (canFit(tasks, sessions, sessionTime, idx - 1)) {
                return true;
            }
            sessions[i] -= tasks[idx];
        }
        return false;
    }
}