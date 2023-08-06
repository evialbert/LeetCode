class Solution {
public:
    int alternatingSubarray(vector<int>& nums) 
    {
        int head = 1, tail = 0, k = 1, len1 = 1, len2 = 1;
        while(head < nums.size())
        {
            if(nums[head]-nums[head-1] == k)
            {
                head++;
                k = -k;
                len1++;
            }
            else
            {
                tail++;
                head = tail+1;
                k = 1;
                len1 = 1;
            }
            len2 = max(len2, len1);
        }
        if(len2 == 1)
        {
            return -1;
        }
        return len2;
    }
};