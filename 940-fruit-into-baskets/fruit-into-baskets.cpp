class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=1, n=fruits.size(), c1=fruits[0], c2=-1, ans=1, l1=0;
        while(r<n){
            if(fruits[r]!=fruits[r-1]){
                if(c2==-1){
                    c2=fruits[r];
                }
                else if(fruits[r]!=c1 && fruits[r]!=c2){
                    c1=fruits[r-1];
                    c2=fruits[r];
                    ans=max(ans, r-l);
                    l=l1;
                }
                l1=r;
            }
            r++;
        }
        return max(ans, r-l);
    }
};