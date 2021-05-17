class Solution {
    public int openLock(String[] deadends, String target) {
        var dead=new HashSet<String>();
        for(var d:deadends) {
            dead.add(d);
        }
        var queue=new LinkedList<String>();
        var visited=new HashSet<String>();
        var cnt=0;
        queue.offer("0000");
        while(!queue.isEmpty()) {
            var size=queue.size();
            for(int i=0;i<size;i++) {
                var s=queue.poll();
                if(s.equals(target)) return cnt;
                if(dead.contains(s)) continue;
                var chars=s.toCharArray();
                
                // for each digits, change up and down
                for(int j=0;j<chars.length;j++) {
                    var val=chars[j]-'0';
                    // move down
                    var d=(val+9)%10;
                    chars[j]=(char)(d+'0');
                    var ds=new String(chars);
                    if(!visited.contains(ds)) {
                        queue.offer(ds);
                        visited.add(ds);
                    }
                    
                    // move up
                    var u=(val+1)%10;
                    chars[j]=(char)(u+'0');
                    var us=new String(chars);
                    if(!visited.contains(us)) {
                        queue.offer(us);
                        visited.add(us);
                    }
                    
                    // change back
                    chars[j]=(char)(val+'0');
                }
            }
            cnt++;
        }
        return -1;
    }
}