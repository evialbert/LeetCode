class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //this appoarch use binear search
        if(nums[nums.size()-1]<0)return nums.size();
        if(nums[0]>0)return nums.size();
        if(nums[0]==0 && nums[nums.size()-1]==0)return 0;

        int s = 0;
        int e = nums.size()-1;

        int mid = s+(e-s)/2;
        //this one finds the first non negative hence tell us
        //the no of negative
        while(s<e){
            if(nums[mid]<0)s=mid+1;
            else e=mid;
            mid = s+(e-s)/2;
        }
        int neg = s;
        //this one finds the first postive hence tell us
        //the no of postive
        e = nums.size()-1;
        mid = s+(e-s)/2;
        while(s<e){
            if(nums[mid]==0)s=mid+1;
            else e=mid;
            mid = s+(e-s)/2;
        }

        int pos = nums.size()-s;
        if(pos>neg)return pos;
        else return neg;
    }
};