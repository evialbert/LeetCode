class Solution {
    public int[] sortByBits(int[] arr) {
        TreeMap<Integer,List<Integer>> tm= new TreeMap<>();
        List<Integer> l;
        int count=0;
        for(int i=0;i<arr.length;i++){
            count=bitCount(arr[i]);
            if(tm.containsKey(count)){
                tm.get(count).add(arr[i]);
            }else{
                tm.put(count,new ArrayList<>());
                tm.get(count).add(arr[i]);
            }
        }
        int index=0;
        for(Map.Entry i : tm.entrySet()){
            l=tm.get(i.getKey()).stream().sorted().collect(Collectors.toList());
            for(int j=0;j<l.size();j++){
                arr[index++]=l.get(j);
            }
        }
        return arr;
    }
    public int bitCount(int n){
        int count=0;
        for(int i=n;i>0;i/=2){
            if(i%2==1){
                count++;
            }
        }
        return count;
    }
}