class Solution {
public:
    int fix(int n, int m,int x){
        if(m>=n) return 0;
        if(n%m==0) return 2+fix(n,m+m,m);
        return 1+fix(n,m+x,x);
    }
    int minSteps(int n) {     
        return fix(n,1,1);
    }
};