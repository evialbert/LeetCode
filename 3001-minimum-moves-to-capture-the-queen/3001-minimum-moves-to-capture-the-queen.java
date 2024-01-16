class Solution {
    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a == e || b == f) {
            if(a == e && a == c && ((d-b) * (d-f) < 0)){
            return 2;
        } 
            if(b == f && b == d && ((c-a) * (c-e) < 0)){
           return 2;
        } 
            return 1;
        }
        if(Math.abs(e-c)==Math.abs(f-d)){
            if(a>Math.min(c,e) && a<Math.max(c,e)){
                if((Math.abs(a-c) == Math.abs(d-b)) && (Math.abs(a-e) == Math.abs(b-f))) {
                    return 2;
                }else{
                    return 1;
                }
            }else{
                return 1;
            }
        }
        return 2;
        
    }
}