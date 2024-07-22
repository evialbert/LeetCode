class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        Map<Integer, String> map = new HashMap<>();
        String[] res = new String[heights.length];
        int i=0;
        while(map.size() < heights.length){
            if(!map.containsKey(heights[i])){
                map.put(heights[i],names[i]);
            }
            i++;
        }
        Arrays.sort(heights);
        for(int j=heights.length-1;j>=0;j--){
           res[j] = map.get(heights[heights.length-j-1]);
        }
        return res;
    }
}