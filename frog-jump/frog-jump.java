class Solution {
    public boolean canCross(int[] stones) {
        Map<Integer,Set<Integer>>helper=new HashMap<>();
        for(int i:stones)helper.put(i,new HashSet<>());
        helper.get(stones[0]).add(1);
        for(int i=0;i<stones.length;i++){
            while(i<stones.length-1&&stones[i+1]==stones[i])i++;
            int p=stones[i];
            Set<Integer>temp=helper.get(p);
            for(int step:temp){
                if(helper.containsKey(p+step)){
                    Set<Integer>next=helper.get(p+step);
                    if(step>1)next.add(step-1);
                    next.add(step);
                    next.add(step+1);
                }
            }
        }
        if(helper.get(stones[stones.length-1]).size()>0)return true;
        return false;
    }
}