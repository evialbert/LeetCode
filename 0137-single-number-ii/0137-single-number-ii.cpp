class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==1){
                return it->first;
            }
        }
        return -1;
    }
};