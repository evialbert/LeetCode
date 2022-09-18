class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        //BFS approach with dijsktras algo -> 0(N)
        Map<Integer,List<List<Integer>>>map=new HashMap<>();
        int[]visit=new int[n];
        boolean[]dp=new boolean[n];
    
        
        Arrays.fill(visit,Integer.MAX_VALUE);
        
        visit[firstPerson]=0;
        visit[0]=0;
        List<Integer>res=new ArrayList<>();
       
        
        for(int i=0;i<n;i++)
            map.put(i,new ArrayList<>());
        
        for(int i=0;i<meetings.length;i++){
            List<Integer>tmp1=new ArrayList<>();
            List<Integer>tmp2=new ArrayList<>();
            
            tmp1.add(meetings[i][1]);
            tmp1.add(meetings[i][2]);
            
            tmp2.add(meetings[i][0]);
            tmp2.add(meetings[i][2]);
            
            map.get(meetings[i][0]).add(tmp1);
            map.get(meetings[i][1]).add(tmp2);
        }
        PriorityQueue<int[]>q=new PriorityQueue<>((a,b)->a[1]-b[1]);
        q.add(new int[]{firstPerson,0});
        q.add(new int[]{0,0});
        
        
        while(!q.isEmpty()){
            int[]tmp=q.remove();
            
            if(!dp[tmp[0]]){
            dp[tmp[0]]=true;
            res.add(tmp[0]);
            
            for(List<Integer>l:map.get(tmp[0])){
                if(l.get(1) >= tmp[1] && visit[l.get(0)] > l.get(1)){
                    visit[l.get(0)]=l.get(1);
                    q.add(new int[]{l.get(0),l.get(1)});
                }
                    
            }
         }
            
        }
        Collections.sort(res);
        return res;
        
        
    }
}