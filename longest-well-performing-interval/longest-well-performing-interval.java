class Solution {
    public int longestWPI(int[] hours) {
        int n = hours.length;
        int[] pre = new int[n+1];
        int[] interval = new int[n];
        for(int i = 0; i < n; ++i){
            if(hours[i] > 8){
                interval[i] = 1;
            }else{
                interval[i] = -1;
            }
        }
        pre[0] = 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,0);
        int max_len = 0;
        for(int i = 1; i <= n; ++i){
            pre[i] = pre[i-1] + interval[i-1];
            if(pre[i] > 0){
                max_len = Math.max(max_len,i);
            }else{
                int look_up = pre[i]-1;
                if(map.containsKey(look_up)){
                    max_len = Math.max(i - map.get(look_up), max_len);
                }
            }
            if(!map.containsKey(pre[i])){
                map.put(pre[i],i);
            }
        }
        return max_len;
        
    }
}