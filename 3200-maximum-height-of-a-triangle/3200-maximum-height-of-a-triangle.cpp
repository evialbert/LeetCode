class Solution {
public:
    int solve(int red, int blue){
        int h=0;
        bool f=1;
        int i=1;
        while(red>0 || blue>0){
            if(f){//height1
                if(i>red) break;
                red-=i;
            }
            else{
                if(i>blue) break;
                blue-=i;
            }
            h++;
            i++;
            f=!f;
        }
        return h;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue),solve(blue,red));
    }
};