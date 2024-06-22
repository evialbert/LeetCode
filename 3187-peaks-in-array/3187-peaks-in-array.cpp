class Solution {
private:
    vector<int> tree;
    int size;
    inline int getPeak(vector<int>& nums, int& pos)
    {
        if(pos <= 0 || pos >= size-1)
            return 0;
        if(nums[pos-1] < nums[pos] && nums[pos] > nums[pos+1])
            return 1;
        else
            return 0;
    }
    inline void build(vector<int>& peaks, int l, int r, int index)
    {
        if(l == r)
        {
            tree[index] = peaks[l];
        }
        else
        {
            int mid = (l+r)/2;
            build(peaks, l, mid, 2*index+1);
            build(peaks, mid+1, r, 2*index+2);
            tree[index] = tree[2*index+1] + tree[2*index+2];
        }
    }
    inline int query(int&ql, int& qr, int l, int r, int index)
    {
        if(ql > r || qr < l)
            return 0;
        else if(ql <= l && r <= qr)
        {
            return tree[index];
        }
        else
        {
            int mid = (l+r)/2;
            return query(ql, qr, l, mid, 2*index+1) + query(ql, qr, mid+1, r, 2*index+2);
        }
    }
    inline void update(int& index, int& val, int l, int r, int treeIndex)
    {
        if(index < l || index > r)
            return;
        else if(l == r)
        {
            tree[treeIndex] = val;
            return;
        }
        else
        {
            int mid = (l+r)/2;
            update(index, val, l, mid, 2*treeIndex+1);
            update(index, val, mid+1, r, 2*treeIndex+2);
            tree[treeIndex] = tree[2*treeIndex+1] + tree[2*treeIndex+2];
            return;
        }
    }
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ret;
        size = nums.size();
        vector<int> peaks(size, 0);
        for(int i=0; i < size; i++)
        {
            peaks[i] = getPeak(nums, i);
        }
        tree.resize(4*size, 0);
        build(peaks, 0, size-1, 0);
        int ql, qr, newpeak, pos, val;
        for(auto q : queries)
        {
            if(q[0] == 1)
            {
                ql = q[1]+1;
                qr = q[2]-1;
                if(qr < ql)
                {
                    ret.push_back(0);
                    continue;
                }
                ret.push_back(query(ql, qr, 0, size-1, 0));
            }
            else
            {
                pos = q[1];
                val = q[2];
                nums[pos] = val;
                for(int i=pos-1; i <= pos+1; i++)
                {
                    newpeak = getPeak(nums, i);
                    if(i >= 0 && i < size && peaks[i] != newpeak)
                    {
                        update(i, newpeak, 0, size-1, 0);
                        peaks[i] = newpeak;
                    }
                }
            }
        }
        return ret;
    }
};