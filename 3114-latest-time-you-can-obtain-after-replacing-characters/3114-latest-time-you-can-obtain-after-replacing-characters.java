class Solution {
    public String findLatestTime(String input) {
        String[] times = new String[12 * 60];
        int hrs = 0;
        int mins = 0;
        
        for (int i = 0; hrs <= 11; i++) {
            String h = (hrs < 10) ? "0" + hrs : "" + hrs;
            String m = (mins < 10) ? "0" + mins : "" + mins;
            String time = h + ":" + m;
            times[i] = time;
            mins++;
            if (mins > 59) {
                mins = 0;
                hrs++;
            }
        }
        
        for (int i = times.length - 1; i >= 0; i--) {
            String time = times[i];
            boolean match = true;
            
            for (int j = 0; j < input.length(); j++) {
                if (input.charAt(j) != '?' && input.charAt(j) != time.charAt(j)) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                return time;
            }
        }
        
        return "";
    }
}