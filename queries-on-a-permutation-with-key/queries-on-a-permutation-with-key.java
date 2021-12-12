class Solution {
    public int[] processQueries(int[] queries, int m) {
        LinkedList<Integer> queue = new LinkedList<>();
        for(int i =0;i<m;i++){
            queue.addLast(i+1);
        }
        int[] arr = new int[queries.length];
        for(int i =0;i<queries.length;i++){
            int a = queries[i];
            int index = queue.indexOf(a);
            arr[i] = index;
            queue.addFirst(queue.remove(index));
        }
        return arr;
    }
}