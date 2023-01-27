class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int temp = 0, n = nums.size();
        vector<int> mx(n);
        
        for(int i=n-1; i>=0; i--)
        {
            temp = temp | nums[i];
            mx[i] = temp;
        }
        
        map<int, int> mp;
        int i=0, j=0, xr=0, flag=1;
        vector<int> ans;
        while(i!=n)
        {
            int num, a;
            if(flag)
            {
                xr = xr | nums[j];
                num = nums[j];
                a=0;
                while(num!=0)
                {
                    if(num%2)
                        mp[a]++;

                    num = num >> 1;
                    a++;
                }
            }
            
            if(xr==mx[i])
            {
                ans.push_back(j-i+1);
                num = nums[i];
                a=0;
                while(num!=0)
                {
                    if(num%2)
                    {
                        mp[a]--;
                        if(mp[a]==0)
                        {
                            int q = (1 << a);
                            xr = xr ^ q;
                            mp.erase(a);
                        }
                    }
                    
                    num = num >> 1;
                    a++;
                }
                i++;
                flag=0;
                if(j<i)
                {
                    flag=1;
                    j = i;
                }
            }
            else
            {
                j++;
                flag=1;
            }
        }
        
        return ans;
    }
};