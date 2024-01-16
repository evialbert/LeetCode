class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e){
            if(d<max(b,f) && d>min(b,f) && c==e){
                return 2;
            }
            else{
                return 1;
            }
        }
        else if(b==f){
            if(c<max(a,e) && c>min(a,e) && d==f){
                return 2;
            }
            else{
                return 1;
            }
        }
        if(abs(f-d)==abs(e-c)){
            if(abs(d-b)==abs(c-a) &&(a<max(c,e) && a>min(c,e)) && (b<max(d,f) && b>min(d,f))){
                return 2;
            }
            else{
                return 1;
            }
        }
        return 2;
    }
};