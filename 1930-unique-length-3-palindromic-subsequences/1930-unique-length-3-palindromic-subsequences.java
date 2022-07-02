class Solution {
    public int countPalindromicSubsequence(String s) {
        Map<Character, List<Integer>> map = new HashMap<>();
        char[] arr = s.toCharArray();
        int result = 0;
        for(int i = 0; i < arr.length;i++){
            if(!map.containsKey(arr[i])){
                List<Integer> list = new LinkedList<>();
                list.add(i);
                map.put(arr[i],list);
            }else{
                map.get(arr[i]).add(i);
            }
        }
       for(Character c : map.keySet()){
           List<Integer> list = map.get(c);
           if(list.size() < 2) continue;
           Set<Character> set = new HashSet<>();
           for(int i = list.get(0) + 1; i< list.get(list.size()-1); i++){
               set.add(arr[i]);
           }
           result = result + set.size();
       }
        return result;
    }
}