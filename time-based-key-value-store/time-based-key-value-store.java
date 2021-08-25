class TimeMap {
    
    Map<String, TreeMap<Integer, String>> map;

    /** Initialize your data structure here. */
    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        TreeMap<Integer, String> values = map.getOrDefault(key, new TreeMap<>());
        values.put(timestamp, value);
        map.put(key, values);
    }
    
    public String get(String key, int timestamp) {
        if (!map.containsKey(key)) return "";
        Integer valueKey = map.get(key).floorKey(timestamp);
        if (valueKey == null) return "";
        return map.get(key).get(valueKey);
    }
}