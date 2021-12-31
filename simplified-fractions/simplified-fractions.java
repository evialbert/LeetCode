class Solution {
    public List<String> simplifiedFractions(int n) {
        HashSet<Double> hs = new HashSet<>();
        List<String> ans = new ArrayList<>();
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= i - 1 ; j++){
                double val = (j * 1.0)/i;
                System.out.println(val);
                if(hs.contains(val))
                    continue;
                hs.add(val);
                String temp = Integer.toString(j) + "/" + Integer.toString(i);
                ans.add(temp);
            }
        }
        return ans;
    }
}