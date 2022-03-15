class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        
        Map<String, List<Integer>> nameToTimesMap = new HashMap<>();
        
        // populate map
        for(int i=0; i<keyName.length; i++) {
            String name = keyName[i];
            int time = convertTimeToMinutes(keyTime[i]);
            if(!nameToTimesMap.containsKey(name)) {
                List<Integer> times = new ArrayList<>();
                times.add(time);
                nameToTimesMap.put(name, times);
            } else {
                nameToTimesMap.get(name).add(time);
            }
        }
        
        // iterate through map entries and populate result
        List<String> result = new ArrayList<>();
        nameToTimesMap.forEach( (name, times) -> {
            Collections.sort(times);
            for(int i=2; i<times.size();i++) {
                
                // compare the current time with the previous to previous time to 
                // determine if its within the same hour
                if( times.get(i) - times.get(i-2) <= 60) {
                    result.add(name);
                    break;
                }
            }
            
        });
        
        // sort results before returning
        Collections.sort(result);
        return result;
    }


    private int convertTimeToMinutes(String time) {
        String[] components = time.split(":");
        int hour = Integer.valueOf(components[0]);
        int mins = Integer.valueOf(components[1]);
        return (hour * 60) + mins;
    }
}