class Solution {
    
    class LogsParser {
        int funcId;
        int timestamp;
        boolean isStart;
        
        public LogsParser(String log) {
            String[] def = log.split(":");
            this.funcId = Integer.parseInt(def[0]);
            this.isStart = def[1].equals("start");
            this.timestamp = Integer.parseInt(def[2]);
        } 
    }
    
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        Stack<LogsParser> stack = new Stack<>();
        int prev = 0;
        for(String log : logs) {
            LogsParser logParser = new LogsParser(log);
            if(!stack.isEmpty()) {
                if(logParser.isStart) {
                    res[stack.peek().funcId] += logParser.timestamp - prev;
                    stack.push(logParser);  
                } else {
                    res[logParser.funcId] += logParser.timestamp - prev + 1;
                    stack.pop();
                }
            } else {
                stack.push(logParser);
            }
            
            prev = logParser.isStart ? logParser.timestamp : logParser.timestamp + 1;
        }
        return res;
    }
}