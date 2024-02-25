class Solution {
    public void dfs(int curnode,Map<Integer,List<Integer>> nodcon,Set<Integer> s2){
        s2.add(curnode);
        if(!nodcon.containsKey(curnode)){
            nodcon.put(curnode,new ArrayList());
        }
        for(int conn:nodcon.get(curnode)){
            if(!s2.contains(conn)){
                dfs(conn,nodcon,s2);
            }
        }
    }
    public boolean canTraverseAllPairs(int[] nums) {
        Map<Integer,Integer> newnode = new HashMap<>();
        Map<Integer,List<Integer>> nodeconn = new HashMap<>();
        Set<Integer> s = new HashSet<>();
        for(int j=0;j<nums.length;j++){
            List<Integer> l = new ArrayList<>();
            while(nums[j]%2==0){
                l.add(2);
                nums[j]/=2;
            }
            for(int k=3;k<=Math.sqrt(nums[j]);k+=2){
                while(nums[j]%k==0){
                    l.add(k);
                    nums[j]/=k;
                }
            }
            if(nums[j]>2){
                l.add(nums[j]);
            }
            for(int k=0;k<l.size();k++){
                if(!newnode.containsKey(l.get(k))){
                    newnode.put(l.get(k),j);
                }
                else{
                    int con1 = j;
                    int con2 = newnode.get(l.get(k));
                    if(!nodeconn.containsKey(con1)){
                        nodeconn.put(j,new ArrayList());
                    }
                    nodeconn.get(con1).add(con2);
                    if(!nodeconn.containsKey(con2)){
                        nodeconn.put(con2,new ArrayList());
                    }
                    nodeconn.get(con2).add(con1);
                }
            }
        }
        dfs(0,nodeconn,s);
        return (s.size()==nums.length);
    }
}