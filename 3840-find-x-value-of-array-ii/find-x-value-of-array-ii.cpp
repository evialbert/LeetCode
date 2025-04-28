class Solution {
    struct Node{
    // record the all [left, right] prefix product.
    // Example: (left), (left, left+1), ... (left,... right)
    public:
        Node(){ // empty node
            fill(remain, remain+5, 0);
            prod = 1;
        }
        int remain[5]; 
        int prod; 
    };

    class SegmentTree{ // 0->1,2 (2n+1 and 2n+2)
        int k, n;
        vector<Node> nodes;
    public:
        SegmentTree(vector<int>& nums, int k){
            this->k = k;
            this->n = nums.size();
            nodes.resize(4*(this->n));
            build(nums, 0, 0, n-1);
        }
        void update(int cur, int left, int right, int target, int val){
            if(left == right){
                for(int i=0; i<k; ++i) nodes[cur].remain[i] = 0;
                nodes[cur].remain[val] = 1;
                nodes[cur].prod = val;
                return;
            }
            int mid = (left + right) / 2;
            if(target <= mid)
                update(2*cur+1, left, mid, target, val);
            else 
                update(2*cur+2, mid+1, right, target, val);
            merge(cur);
        }
        Node query(int cur, int qL, int qR, int left, int right){
            if(qR < left || qL > right) return Node(); // empty
            if(qL <= left && right <= qR) return nodes[cur];
            int mid = (left + right) / 2;
            Node nLeft = query(2*cur+1, qL, qR, left, mid);
            Node nRight = query(2*cur+2, qL, qR, mid+1, right);
            merge(nLeft, nRight);
            return nLeft;
        }
    private:
        void build(vector<int>& nums, int cur, int left, int right){
            if(left == right){
                nodes[cur].remain[nums[left]] = 1;
                nodes[cur].prod = nums[left];
                return;
            } 
            int mid = (left + right)/2;
            build(nums, 2*cur+1, left, mid);
            build(nums, 2*cur+2, mid+1, right);
            merge(cur);
        }
        void merge(int cur){
            // merge the 2*cur+1 and 2*cur+2 node to cur
            int left = 2*cur+1;
            int right = 2*cur+2;
            nodes[cur].prod = (nodes[left].prod * nodes[right].prod) % k;
            // The part [left ~ mid]'s prefix still include in the [left, right] prefix.
            for(int i=0; i<k; ++i) nodes[cur].remain[i] = nodes[left].remain[i];
            for(int i=0; i<k; ++i){
                int newVal = (i*nodes[left].prod) % k;
                nodes[cur].remain[newVal] += nodes[right].remain[i];
            }
        }
        void merge(Node& n1, Node& n2){
            // merge the n1 and n2 node to n1
            for(int i=0; i<k; ++i){
                int newVal = (i*n1.prod) % k;
                n1.remain[newVal] += n2.remain[i];
            }
            n1.prod = (n1.prod * n2.prod) % k;
        }
    };
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        for(auto& val : nums){
            val %= k;
        }
        for(auto& query : queries){
            query[1] %= k;
        }
        SegmentTree segmentTree(nums, k);
        vector<int> res;
        for(auto& query : queries){
            int ind = query[0];
            int value = query[1];
            int start = query[2];
            int x = query[3];
            // update nums
            segmentTree.update(0, 0, n-1, ind, value);
            res.push_back(segmentTree.query(0, start, n-1, 0, n-1).remain[x]);
        }
        return res;
    }
};