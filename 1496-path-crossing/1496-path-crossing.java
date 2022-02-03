class Solution {
    public boolean isPathCrossing(String path) {
        int xcord=0;
        int ycord=0;
        HashMap<String,Boolean> hm = new HashMap<>();
        String cord =Integer.toString(xcord)+"="+Integer.toString(ycord);
        hm.put(cord ,true);
        for(int i=0 ;i<path.length();i++){
            if(path.charAt(i)=='N') ycord++;
            else if(path.charAt(i)=='E') xcord++;
            else if(path.charAt(i)=='S') ycord--;
            else xcord--;
            String temp = Integer.toString(xcord)+"="+Integer.toString(ycord);
            if(hm.containsKey(temp)){
                return true;
            }
            else hm.put(temp , true);
            
           
        }
         return false;
    }
}