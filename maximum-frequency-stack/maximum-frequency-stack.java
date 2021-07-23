class FreqStack {

    HashMap<Integer , Stack<Integer>> map1 = new HashMap<>();
    HashMap<Integer , Integer> map2 = new HashMap<>();
    int maxFreq=-1;
    public FreqStack() {
        
    }
    
    public void push(int val) {
        map2.put(val , map2.getOrDefault(val , 0)+1);
        int freq = map2.get(val);
        maxFreq = Math.max(maxFreq , freq);
        if(!map1.containsKey(freq)){
            map1.put(freq , new Stack<Integer>());
           
        }
        map1.get(freq).push(val);
        
    }
    
    public int pop() {
        int ans = map1.get(maxFreq).pop();
        if(map1.get(maxFreq).isEmpty()==true){
            //map1.remove(maxFreq);
            maxFreq--;
        }
       
        map2.put(ans , map2.get(ans)-1);
        
        return ans;
        
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */