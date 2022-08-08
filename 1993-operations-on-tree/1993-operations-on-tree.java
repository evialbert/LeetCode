class LockingTree {

    int[] parent;
    Map<Integer, Integer> lock = new HashMap();
    Map<Integer, Set<Integer>> descendentWithLock = new HashMap();
    
    public LockingTree(int[] parent) {
        this.parent = parent;
    }
    
    public boolean lock(int num, int user) {
        if(lock.containsKey(num)){  
            return false;
        }
        lock.put(num, user);
        storeDescendentLockDetails(num, num);
        return true;
    }
    
    private void storeDescendentLockDetails(int numWithLock, int num){
        if(num == -1)
            return;
        
        if(descendentWithLock.get(parent[num]) == null){
            descendentWithLock.put(parent[num], new HashSet());
        }
        descendentWithLock.get(parent[num]).add(numWithLock);
        storeDescendentLockDetails(numWithLock, parent[num]);
    }
    public boolean unlock(int num, int user) {
        if(!lock.containsKey(num) || lock.get(num) != user){
            return false;
        }
        lock.remove(num);
        deleteDescendentLockDetails(num, num);
        return true;
    }
    
     private void deleteDescendentLockDetails(int numWithLock, int num){
        if(num == -1)
            return;
        if(descendentWithLock.get(parent[num]) == null){
            descendentWithLock.put(parent[num], new HashSet());
        }
        descendentWithLock.get(parent[num]).remove(numWithLock);
        deleteDescendentLockDetails(numWithLock, parent[num]);
    }
    public boolean upgrade(int num, int user) {
        if(lock.containsKey(num))
            return false;
        
        if(!descendentWithLock.containsKey(num) || descendentWithLock.get(num) == null
           || descendentWithLock.get(num).size() == 0){
            return false;
        }
        
        if(checkIfAnyAncestorHasLock(num)){
            return false;
        }
        
        lock.put(num, user);
        storeDescendentLockDetails(num, num);
        
        List<Integer> deletedChildNodes = new ArrayList();
        
        for(Integer i : descendentWithLock.get(num)){
            lock.remove(i);
            deletedChildNodes.add(i);
        }
        
        for(Integer i : deletedChildNodes){
            deleteDescendentLockDetails(i, i);
        }
        descendentWithLock.put(num, new HashSet());
        return true;
    }
    
    private boolean checkIfAnyAncestorHasLock(int num){
        if(num == -1){
            return false;
        }
        if(lock.containsKey(parent[num])){
            return true;
        }
        if(checkIfAnyAncestorHasLock(parent[num])){
            return true;
        }
        return false;
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree obj = new LockingTree(parent);
 * boolean param_1 = obj.lock(num,user);
 * boolean param_2 = obj.unlock(num,user);
 * boolean param_3 = obj.upgrade(num,user);
 */