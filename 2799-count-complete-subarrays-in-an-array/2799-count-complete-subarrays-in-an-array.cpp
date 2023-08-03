class Solution {
public:
    int b_s(unordered_map<int,vector<int>> &map,int num,int l_lim,int r_lim){
        int l_ind=0,r_ind=map[num].size()-1,mid;
        while(l_ind<=r_ind){
            mid=(l_ind+r_ind)/2;
            if(map[num][mid]<l_lim) l_ind=mid+1;
            else if(map[num][mid]>r_lim) r_ind=mid-1;
            else return 1;
        }
        return 0;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        int cnt=0,left,dist=0;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])==map.end()){
                left=i;
                dist++;
            }
            map[nums[i]].push_back(i);
        }
        for(int i=left;i<nums.size();i++){
            cnt++;
            for(int j=0;j<=i-1;j++){
                if(b_s(map,nums[j],j+1,i)) cnt++;
                else break;
            }
        }
        return cnt;
    }
};