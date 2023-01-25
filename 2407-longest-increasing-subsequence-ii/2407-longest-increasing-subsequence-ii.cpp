class Solution {
public:
    vector<int> seg;
    
    int getSize(int n){
        int size = 1;
        for(;size < n; size<<=1);
        return size;
    }
    
    void insert(int index, int value, int size){
        for(int i = index + size - 1; i > 0; seg[i]=max(seg[i], value), i>>=1);
    }
    
    int get(int start, int end, int index, int l, int r){
        if(r < start || l > end)
            return 0;
        if(start <= l && r <= end){
            return seg[index];
        }
        int mid = (l + r) >> 1;
        return max(
            get(start, end, index << 1, l, mid), 
            get(start, end, (index << 1) + 1, mid + 1, r)
        );
    }
        
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int size = getSize(1e5);
        seg = vector<int>(size * 2, 0);
        
        int ans{};
        
        for(int i = 1; i <= n; i++){
            int num = nums[i - 1];
            int mx = get(max(1, num - k), num - 1, 1, 1, size);
            insert(num, mx + 1, size);
            ans = max(ans, seg[num + size - 1]);
        }
        
        return ans;
    }
};