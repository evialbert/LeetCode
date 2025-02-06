class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // calculate all products possible 

        int n=nums.size();
        vector<int>product;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
             product.push_back(nums[i]*nums[j]);
            }
        }

        // calculate the frequency of each element using hashmap
        int ans=0;
        std::unordered_map<int, int> frequency_map;
        for (const auto& i : product) {
        frequency_map[i]++;
        }


        for (const auto& m:frequency_map)
        { 
          int f=m.second;
        if (f>1)
        {
            ans+=f*(f-1)*4;
        }
        }
    return ans;
    }
};