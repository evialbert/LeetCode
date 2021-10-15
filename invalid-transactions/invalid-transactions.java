class Solution {
    public List<String> invalidTransactions(String[] transactions) {        
        List<String> r = new ArrayList();
        
        HashMap<String, ArrayList<Data>> m = new HashMap();
        int[] flags = new int[transactions.length];
        
        int index = 0;
        for(String t: transactions) {
            String temp[] = t.split(",");
            
            Data d = new Data();
            
            d.index = index;
            d.name = temp[0];
            d.time = Double.parseDouble(temp[1]);
            d.amount = Double.parseDouble(temp[2]);
            d.city = temp[3];
                        
            if(d.isOver1k()) {
                flags[index] = 1;
            }
            
            if(m.containsKey(temp[0])) {
                ArrayList<Data> l = m.get(temp[0]);
                Data curr = d;
                
                for(int i=0; i < l.size(); i++) {
                    Data prev = l.get(i);

                    if(curr.isLessThan60(prev) && curr.isDiffCity(prev)) {
                        flags[prev.index] = 1;
                        flags[curr.index] = 1;
                    }
                }
                
                l.add(d);
                m.put(temp[0], l);
            } else {
                ArrayList l = new ArrayList();
                l.add(d);
                m.put(temp[0], l);
            }
            index++;
        }
        
        for(int i = 0; i < transactions.length; i++) {
            if(flags[i] == 1) {
                r.add(transactions[i]);
            }
        }
        
        return r;
    }
    
    class Data {
        int index;
        String name;
        double time;
        double amount;
        String city;
        
        boolean isDiffCity(Data o) {
            return !o.city.equals(city);
        }
        
        boolean isOver1k() {
            return amount > 1000;
        }
        
        boolean isLessThan60(Data o) {
            return Math.abs(o.time - time) <= 60;
        }
        
        @Override
        public String toString() {
            return name + " " + time + " " + amount + " " + city;
        }
    }
}