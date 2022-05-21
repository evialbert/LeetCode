class Solution {
    public int minimumTeachings(int n, int[][] L, int[][] F) {
        BitSet[] bit = new BitSet[L.length];
        Arrays.setAll(bit, o -> new BitSet(n + 1));
        for (int i = 0; i < L.length; i++){
            for (int l : L[i]){
                bit[i].set(l);
            }
        }
        Set<Integer> teach = new HashSet<>();
        for (int[] f : F){
            BitSet t = (BitSet)bit[f[0] - 1].clone();
            t.and(bit[f[1] - 1]);
            if (t.isEmpty()){
                teach.add(f[0] - 1);
                teach.add(f[1] - 1);
            }
        }
        int[] count = new int[n + 1];
        for (int person : teach){
            for (int l : L[person]){
                count[l]++;
            }
        }

        return teach.size() - Arrays.stream(count).max().getAsInt();
    }
}