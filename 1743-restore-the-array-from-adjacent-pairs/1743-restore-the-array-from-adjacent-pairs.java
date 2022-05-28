class Solution {
public int[] restoreArray(int[][] A) {
    
    if(A.length == 1) return A[0];
    
    Map<Integer, List<Integer>> map = new HashMap();
    for(int i=0; i< A.length; i++){
        int left =  A[i][0];
        int right = A[i][1];
        
        if(map.containsKey(left)){
            map.get(left).add(right);
        }else{
            List<Integer> arr = new ArrayList();
            arr.add(right);
            map.put(left, arr);
        }
        
        if(map.containsKey(right)){
            map.get(right).add(left);
        }else{
            List<Integer> arr = new ArrayList();
            arr.add(left);
            map.put(right, arr);
        }
    }
    
    int head = Integer.MIN_VALUE, tail = Integer.MIN_VALUE;
    for(Map.Entry<Integer, List<Integer>> entry : map.entrySet()){
        if(entry.getValue().size() == 1){
            if(head == Integer.MIN_VALUE) 
                head = entry.getKey();
            else 
                tail = entry.getKey();
        }
    }
    
    Set<Integer> visited = new HashSet();
    int[] ans = new int[A.length + 1];
    ans[0] = head;
    int index = 0;
    visited.add(head);
    while(!map.isEmpty()){
        if(map.containsKey(ans[index])){
            for(int val : map.get(ans[index])){
                if(val == ans[index] || visited.contains(val)) 
                    continue;
                else {
                    ans[index+1] = val;
                    visited.add(val);
                }
            }
            map.remove(ans[index]);
            index ++;
        }
    }
    
    return ans;
}
}