// O(len(s) + len(query)*log(len(s)))
// each query log(len(s)) time
    
// TreeMap: candle idx and how many plates before it
//     find lowest i >= query[0]
//     find closest j <= query[1]
//     if j <= i: return 0
//     find number of plate between i and j using TreeMap values

class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        TreeMap<Integer,Integer> plateCntBeforeCandles = new TreeMap<>();
        int plateCnt = 0;
        for (int i=0; i<s.length(); i++){
            if (s.charAt(i)=='|'){
                plateCntBeforeCandles.put(i,plateCnt);
            }
            else{
                plateCnt++;
            }
        }
        plateCntBeforeCandles.put(-1,-1);
        plateCntBeforeCandles.put(s.length(),-1);
        
        int[] res = new int[queries.length];
        for (int i=0; i<queries.length; i++){
            int[] query = queries[i];
            int leftClosest = plateCntBeforeCandles.ceilingKey(query[0]);
            int rightClosest = plateCntBeforeCandles.floorKey(query[1]);
            if (leftClosest>=rightClosest){
                continue;
            }
            res[i] = plateCntBeforeCandles.get(rightClosest) - plateCntBeforeCandles.get(leftClosest);
        }
        
        return res;
    }
}