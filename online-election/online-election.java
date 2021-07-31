class TopVotedCandidate {

    TreeMap<Integer,Integer> maxMap = new TreeMap();
    
    public TopVotedCandidate(int[] persons, int[] times) {
        TreeMap<Integer,LinkedHashMap<Integer,Integer>> map = new TreeMap();
        int max=Integer.MIN_VALUE,person=-1;
        for(int i=0;i<times.length;i++){
            LinkedHashMap<Integer,Integer> count = new LinkedHashMap();
            if(map.isEmpty()){
                count.put(persons[i],count.getOrDefault(persons[i],0)+1);
                int curr= count.getOrDefault(persons[i],0)+1;
                if(curr>=max){
                    max = curr;
                    person = persons[i];
                }
            }else{
                count = (LinkedHashMap)map.get(times[i-1]).clone();
                count.put(persons[i],count.getOrDefault(persons[i],0)+1);
                int curr = count.getOrDefault(persons[i],0)+1;
                if(curr>=max){
                    max = curr;
                    person = persons[i];
                }
            }
            map.put(times[i],count);
            maxMap.put(times[i],person);
        }    
        
    }
    
   
    
    public int q(int t) {
        if(maxMap.containsKey(t)){
            return maxMap.get(t);
        }else if(maxMap.lowerKey(t)!=null){
            return maxMap.get(maxMap.lowerKey(t));
        }
        return -1;
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */