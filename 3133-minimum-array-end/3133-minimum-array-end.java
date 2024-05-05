class Solution {
    public long minEnd(int n, int x) {

        long num = x , one = 1;

        List<Integer> unsetBits = new ArrayList<>();
        for(int bit = 0 ; bit < 63 ; bit++){
            if((num >> bit & one ^ one) == 1){
                unsetBits.add(bit);
            }
        }

        long mask = n - 1;
        for(int index = 0 ; index < unsetBits.size() ; index++){
            if((mask >> index & one) == 1){
                num |= one << unsetBits.get(index);
            }
        }
        return num;
    }
}