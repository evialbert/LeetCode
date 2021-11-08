class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        if(initialBoxes.length==0)return 0;
        int len = status.length;
        if(len==1)return status[0]==1&&initialBoxes[0]==0?candies[0]:0;
        
        Queue<Integer> que = new LinkedList<Integer>();
        int ret = 0;
        
        boolean v[] = new boolean[len];
        for(int x:initialBoxes){
            v[x]=true;
            if(status[x]==1)que.add(x);
        }
        
        int o;
        while(!que.isEmpty()){
            o=que.poll();
            ret+=candies[o];
            for(int b:containedBoxes[o]){
                if(v[b])continue;
                v[b]=true;
                if(status[b]==1)que.add(b);
            }
            for(int k:keys[o]){
                if(status[k]==1)continue;
                status[k]=1;
                if(v[k])que.add(k);
            }
        }
        
        return ret;
    }
}