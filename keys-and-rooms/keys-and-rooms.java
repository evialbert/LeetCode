class Solution {
    HashSet<Integer> hs;
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        hs=new HashSet<Integer>();
        hs.add(0);
        dfs(hs,rooms,0);
        for(int i=0;i<rooms.size();i++){
            if(!hs.contains(i)){
                return false;
            }
        }
        return true;
        
    }
    public void dfs(HashSet<Integer> arr,List<List<Integer>> rooms,int index){
            for(int i=0;i<rooms.get(index).size();i++){
                if(!hs.contains(rooms.get(index).get(i))){
                    hs.add(rooms.get(index).get(i));
                    dfs(arr,rooms,rooms.get(index).get(i));
                }
            }
        
    }
}