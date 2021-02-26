class segmentNode {
    
    int start, end, val;
    segmentNode left, right;
    
    public segmentNode(int start, int end, int val) {
        this.start = start;
        this.end = end;
        this.val = val;
    }
    
    public segmentNode(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

class NumArray {
    
    segmentNode root;

    public NumArray(int[] nums) {
        if (nums.length > 0)
            this.root = createSeg(nums, 0, nums.length - 1);
        // traverse(this.root);
    }
    
    public void update(int i, int val) {
        fndAndUpdate(i, val, this.root);
    }
    
    // let's pass back the updated value
    public int fndAndUpdate(int i, int val, segmentNode curr) {
        if (curr.start == curr.end) { // found our element
            return curr.val = val; // update value
        } else {
            int mid = curr.start + (curr.end - curr.start) / 2;
            int diff = 0;
            if (mid >= i)
                diff = fndAndUpdate(i, val, curr.left); // go left if they are equal because we put more values in the left tree
            else
                diff = fndAndUpdate(i, val, curr.right);
            
            curr.val = curr.left.val + curr.right.val;
            return diff;
        }
    }
    
    public int sumRange(int i, int j) {
        return fnd(i, j, this.root);
    }
    
    public int fnd(int i, int j, segmentNode curr) {
        if (curr.start == i && curr.end == j)
            return curr.val;
        
        int mid = curr.start + (curr.end - curr.start) / 2;
        if (i >= mid + 1) // right is one past the mid (because there are more points on the left node)
            return fnd(i, j, curr.right);
        else if (j <= mid)
            return fnd(i, j, curr.left);
        else
            return fnd(i, mid, curr.left) + fnd(mid + 1, j, curr.right);
    }
    
    public segmentNode createSeg(int[] nums, int start, int end) {
        if (start > end)
            return null;
        
        if (start == end)
            return new segmentNode(start, end, nums[start]);
        
        segmentNode tmp = new segmentNode(start, end);
        tmp.left = createSeg(nums, start, start + (end - start) / 2); 
        tmp.right = createSeg(nums, start + (end - start) / 2 + 1, end);
        if (tmp.left != null)
            tmp.val += tmp.left.val;
        if (tmp.right != null)
            tmp.val += tmp.right.val;
        return tmp;
    }
    
    public void traverse(segmentNode curr) {
        if (curr == null)
            return;
        
        System.out.println(curr.val);
        traverse(curr.left);
        traverse(curr.right);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */