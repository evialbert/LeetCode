class Solution {
    public int[] avoidFlood(int[] rains) {
        HashMap<Integer, Integer> fullLakes = new HashMap();
        TreeSet<Integer> dryDays = new TreeSet();
        int[] res = new int[rains.length];
        
        for(int day = 0; day < rains.length; day++) {
            if(rains[day] == 0) {
                dryDays.add(day);
                res[day] = 1;
            } else {
                res[day] = -1;
                int lake = rains[day];
                if (fullLakes.get(lake) != null) {
                    Integer earliestDryDay = dryDays.ceiling(fullLakes.get(lake));
                    if (earliestDryDay == null)
                        return new int[]{};
                    else {
                        // take this day to dry the lake.
                        dryDays.remove(earliestDryDay);
                        fullLakes.put(lake,day);
                        res[earliestDryDay] = lake;
                    }
                } else {
                    fullLakes.put(lake,day);
                }
            }
        }
        
        return res;
        
    }
}