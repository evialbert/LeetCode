class Solution {
    public int minJumps(int[] arr) {
        Map<Integer, List<Integer>> map=new HashMap<>();
        int n=arr.length;
        int[]visited=new int[n];
        for(int i=0;i<n;i++){
            if(map.containsKey(arr[i])){
                map.get(arr[i]).add(i);
            }else map.put(arr[i],new ArrayList<>(List.of(i)));
        }
        int ans=0;
        Queue<Integer>queue=new LinkedList<>();
        queue.offer(0);
        visited[0]=1;
        while(!queue.isEmpty()){
            int size=queue.size();
            for(int i=0;i<size;i++){
                int cur=queue.poll();
                if(cur==n-1)return ans;
                if(cur-1>=0&&visited[cur-1]==0){
                    visited[cur-1]=1;
                    queue.offer(cur-1);
                }
                if(cur+1<=n-1&&visited[cur+1]==0){
                    visited[cur+1]=1;
                    queue.offer(cur+1);
                }
                if(map.containsKey(arr[cur])){
                    for(int val:map.get(arr[cur])){
                       if(visited[val]==0){
                           queue.offer(val);
                           visited[val]=1;
                       }
                    }
                    map.remove(arr[cur]);
                }
            }
            ans++;
        }
        return -1;

    }
}