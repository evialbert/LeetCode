class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        int maxfreq = 0;
        int ans = -1;
        
       
        for(auto i = m.begin();i!=m.end();i++){
            if(i->first %2==0 && i->second>maxfreq){
                maxfreq = i->second;
                ans = i->first;
            }
        }
        return ans;
    }
};