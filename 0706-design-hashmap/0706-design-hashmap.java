class MyHashMap {
private static ArrayList<Integer> keys, values;
public MyHashMap() {
    keys = new ArrayList<Integer>();
    values = new ArrayList<Integer>();
}
public void put(int key, int value) {
    int i;
    if((i = keys.indexOf(key)) != -1)
        values.set(i, value);
    else{
        keys.add(key);
        values.add(value);
    }
}
public int get(int key) {
    int i;
    if((i = keys.indexOf(key)) != -1)
        return values.get(i);
    return -1;
}
public void remove(int key) {
    int i = keys.indexOf(key);
    if(i != -1){
        keys.remove(i);
        values.remove(i);
    }
}
}
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */