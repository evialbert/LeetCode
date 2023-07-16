class Solution {
public:
    int gcd(int a,int b){
        if (b==0) return a;
        return gcd(b,a%b);
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int mmax=*max_element(nums.begin(),nums.end());
        int ans=0;
        int arr[mmax+1];
        memset(arr,0,sizeof(arr));
        for (int i: nums) arr[i]=1;
        for (int x=1;x<=mmax;x++){
            int curGCD=0;
            for (int y=x;y<=mmax;y+=x){
                if (arr[y]==1){
                    curGCD=gcd(curGCD,y);
                    if (curGCD==x){
                        ans+=1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};