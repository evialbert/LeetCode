class Solution {
public:
    int sumDistance(std::vector<int>& nums, std::string& s, int d) {
        const int MOD = 1000000007;
        int n = nums.size();
        vector<long long int> a(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='R')
                a[i]=nums[i]+d;
            else if(s[i]=='L') {
                a[i]=nums[i]-d;
            }
                
        }
       
        sort(a.begin(),a.end());
        long long int diff=-1*a[0];
        for(int i=0;i<n;i++){
            a[i]+=diff;
            // cout<<a[i]<<" ";
        }
        
        vector<long long int>b(n-1,0);
        
        for(int i=0;i<n-1;i++){
            b[i]=a[i+1]-a[i];
        }
        long long  unsigned int i=n-1,j=1;
        long long  unsigned int  ans = 0;
        for(int z=0;z<n-1;z++){
            ans=(ans+(b[z]*i*j))%MOD;
            i--;
            j++;
        }
        return (int)ans;
        
    }
};