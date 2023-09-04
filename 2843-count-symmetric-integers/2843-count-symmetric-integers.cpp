class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int n=s.size();
            if(n%2) continue;
            int chks=0,chke=0;
            for(int j=0,k=n-1;j<n/2,k>=n/2;j++,k--){
                chks+=(int)s[j];
                chke+=(int)s[k];
            }
            if(chks==chke) ans++;
        }
        return ans;
    }
};