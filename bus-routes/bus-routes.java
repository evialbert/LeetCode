class Solution {
  
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if(source==target)return 0;
        Queue<Pair> queue = new LinkedList<>();
        boolean visitedBusNo[] = new boolean[routes.length];
        HashSet<Integer> visitedBusStopNo = new HashSet<>();
        
        HashMap<Integer , ArrayList<Integer>> map = new HashMap<>();
        //filling of hashmap
        for(int i=0;i<routes.length;i++){
            for(int j=0;j<routes[i].length;j++){
                ArrayList<Integer> bussesNo = map.getOrDefault(routes[i][j] , new ArrayList<>());
                bussesNo.add(i);
                map.put(routes[i][j] , bussesNo);
            }
        }
        
        queue.add(new Pair(source , 0));
        while(!queue.isEmpty()){
            int size = queue.size();
            while(size-- >0){
                Pair rp = queue.poll();
                if(rp.busStopNo == target){
                    return rp.NoofBusReq;
                }
                ArrayList<Integer> busNo = map.get(rp.busStopNo);
                for(int bus : busNo){
                    if(visitedBusNo[bus]==false){
                        visitedBusNo[bus]=true;
                        for(int j=0;j<routes[bus].length;j++){
                            if(!visitedBusStopNo.contains(routes[bus][j])){
                                visitedBusStopNo.add(routes[bus][j]);
                                queue.add(new Pair(routes[bus][j] , rp.NoofBusReq+1));
                                // if(routes[bus][j]==target)return rp.NoofBusReq;
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
}

 public  class Pair{
        int busStopNo;
        int NoofBusReq;
        Pair(int busStopNo , int NoofBusReq ){
            this.busStopNo = busStopNo;
            this.NoofBusReq = NoofBusReq;
        }
    }