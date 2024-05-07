class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        HashMap<String,Integer> hm=new HashMap<>();
        int maxcount=0;
        for(int i=0;i<=word.length()-k;i+=k){
            hm.put(word.substring(i,i+k),hm.getOrDefault(word.substring(i,i+k),0)+1);
            maxcount=Math.max(maxcount,hm.get(word.substring(i,i+k)));
        }
        return word.length()/k-maxcount;
    }
}