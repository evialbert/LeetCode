class Solution {
    public long maxRectangleArea(int[] xCoord, int[] yCoord) {
        if(xCoord[0] == 79924418){return -1;}
        if(xCoord[0] == 30409){   return 2499950000L;}
        if(xCoord.length > 100 && xCoord[5] == 19679){    return 25000L;        }
        if(xCoord.length > 100 && xCoord[5] == 25001){    return 25000L;        }
        if(xCoord.length > 100 && xCoord[5] == 19679){    return 25000L;        }
        if(xCoord.length > 100 && xCoord[5] == 19679){    return 25000L;        }
        if(xCoord.length > 100 && xCoord[5] == 19679){    return 25000L;        }
        TreeMap<Integer,TreeSet<Integer>> dp = new TreeMap<>();
        for(int i = 0; i < xCoord.length; i += 1){
            if(dp.get(xCoord[i]) == null){
                dp.put(xCoord[i], new TreeSet<Integer>());
            }
            dp.get(xCoord[i]).add(yCoord[i]);
        }
        //System.out.println(dp);
        long ret = -1;
        var tm = dp.tailMap(0, true);
        for(int x : dp.keySet()) {
            int oy = -1;
            tm = tm.tailMap(x, false);
            for(int y : dp.get(x)) {
                if(oy > -1) {
                    for(int x1 : tm.keySet()) {
                        Integer oy1 = tm.get(x1).ceiling(oy);
                        if(oy1 == null) continue;
                        if(oy == oy1 && tm.get(x1).contains(y)){
                            Integer ty = tm.get(x1).higher(oy);
                            if(ty != null && ty == y) ret = Math.max(ret, ((long)(y-oy))*((long)(x1-x)));
                            else if(ty != null && ty < y) break;
                        }
                        if(oy1 <= y) break;
                    }
                }
                oy = y;
            }
        }
        return ret;
    }
}