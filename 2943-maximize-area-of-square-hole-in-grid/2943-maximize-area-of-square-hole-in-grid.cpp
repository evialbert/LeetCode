class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {

        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int mx=0,mxc=0;
        int c=1;
        for(int i=0;i<h.size()-1;i++){
                if(h[i+1]-h[i]==1){
                c++;
                }
            else
            {
                mxc=max(mxc,c);
                c=1;
            }
            }
        mxc=max(mxc,c);
        c=1;
         for(int i=0;i<v.size()-1;i++){
                if(v[i+1]-v[i]==1){
                c++;
                }
            else
            {
                mx=max(mx,c);
                c=1;
            }
            }
        
        mx=max(mx,c);
        int mn=INT_MAX;
        mn=min(mx,mxc);
        return (mn+1) * (mn+1);
        

    }
};