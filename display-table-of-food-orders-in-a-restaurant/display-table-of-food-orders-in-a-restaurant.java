class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        int[][] tab = new int[501][1001];
        Map<String, Integer> fm = new HashMap<>();
        int i = 1;
        for (List<String> o:orders) {
            
            int foodK = -1;
            if (fm.containsKey(o.get(2))) {
                foodK = fm.get(o.get(2));    
            } else {
                foodK = i++;
                fm.put(o.get(2), foodK);
            }
            int tbl = Integer.valueOf(o.get(1));
            tab[tbl][foodK]++;
            tab[tbl][0]++;
        }
        List<List<String>> l = new ArrayList<>();
        List<String> sk=new ArrayList(fm.keySet());
        Collections.sort(sk);
        List<String> l1 = new ArrayList<>();
        l1.add("Table");
        l1.addAll(sk);
        l.add(l1);
        for (int j=0;j<tab.length;j++) {
            if (tab[j][0]>0) {
                List<String> l2 = new ArrayList<>();
                l2.add(""+j);
                for (String fd:sk) {
                    l2.add(""+tab[j][fm.get(fd)]);    
                }
                l.add(l2);
            }
        }
        return l;
    }
}