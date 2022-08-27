class StockPrice {
    TreeSet<Integer> values;
    Map<Integer, Integer> data;
    Map<Integer, Integer> count;
    int time;
    
    public StockPrice() {
        data = new HashMap<>();
        values = new TreeSet<>();
        count = new HashMap<>();
        time = 0;
    }
    
    public void update(int timestamp, int price) {
        if(data.containsKey(timestamp)) {
            int prevPrice = data.get(timestamp);
            count.put(prevPrice, count.get(prevPrice) - 1);
            if(count.get(prevPrice) == 0) {
                values.remove(prevPrice);
            }
        }
        
        data.put(timestamp, price);
        values.add(price);
        count.put(price, count.getOrDefault(price, 0) + 1);
        time = Math.max(timestamp, time);
    }
    
    public int current() {
        return data.get(time);
    }
    
    public int maximum() {
        return values.last();
    }
    
    public int minimum() {
        return values.first();
    }
}
/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice obj = new StockPrice();
 * obj.update(timestamp,price);
 * int param_2 = obj.current();
 * int param_3 = obj.maximum();
 * int param_4 = obj.minimum();
 */