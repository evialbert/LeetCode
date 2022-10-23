class Bitset {

    Set<Integer> o = new HashSet<>();
    int s = 0;
    boolean flip = false;
    public Bitset(int size) {
        s = size;
    }
    
    public void fix(int idx) {
        if(flip)
            o.remove(idx);
        else
            o.add(idx);
    }
    
    public void unfix(int idx) {
        if(flip)
            o.add(idx);
        else
            o.remove(idx);
    }
    
    public void flip() {
        flip = !flip;
    }
    
    public boolean all() {
        return flip ? o.isEmpty() : o.size()== s;
    }
    
    public boolean one() {
        return flip ? s - o.size() > 0 : !o.isEmpty();
    }
    
    public int count() {
        return flip ? s - o.size() : o.size();        
    }
    
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s;i++){
            if(flip){
                if(o.contains(i)){
                    sb.append(0);
                }else {
                    sb.append(1);
                }
            }else {
                if(o.contains(i)){
                    sb.append(1);
                }else {
                    sb.append(0);
                }
            }
        }
        return sb.toString();
    }
}

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset obj = new Bitset(size);
 * obj.fix(idx);
 * obj.unfix(idx);
 * obj.flip();
 * boolean param_4 = obj.all();
 * boolean param_5 = obj.one();
 * int param_6 = obj.count();
 * String param_7 = obj.toString();
 */