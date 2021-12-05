class Solution {

    HashMap<Integer, Integer> map = new HashMap();
    int maxTime = 0;

    public int numOfMinutes(int n, int headID, int[] managers, int[] informTime) {

        map.put(headID, informTime[headID]);
        for (int k = 0; k < managers.length; k++) {
            if (k == headID) continue;
            int time = informTime(managers[k], managers, informTime);
            maxTime = Math.max(maxTime, time);
        }
        return maxTime;
    }

    // time for the manager to get the information. 
    private int informTime(int manager, int[] managers, int[] informTime) {

        if (map.containsKey(manager)) return map.get(manager);
        int time = informTime(managers[manager], managers, informTime) + informTime[manager];
        map.put(manager, time);
        return time;
    }
}