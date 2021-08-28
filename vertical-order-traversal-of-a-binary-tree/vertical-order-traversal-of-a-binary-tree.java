class Solution {
    class Pair {
        TreeNode node;
        int width;
        
        Pair(TreeNode node, int width) {
            this.node = node;
            this.width = width;
        }
    }
    
    int leftWidth = 0, rightWidth = 0;
    
    public void width(TreeNode node, int width) {
        if(node == null)
            return;
            
        leftWidth = Math.min(leftWidth, width);
        rightWidth = Math.max(rightWidth, width);
        
        width(node.left, width - 1);
        width(node.right, width + 1);
        
        return;
    }
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> arr = new ArrayList<>();
        
        if(root == null)
            return arr;
            
        width(root, 0);
        int wid = rightWidth - leftWidth + 1;
        
        for(int i = 0; i < wid; i++) 
            arr.add(new ArrayList<>());
        
        // here min priority queue is used because we want the elements of same width and vertical order in sorted form
        // Two queues are used so that the parent and child nodes are seperated at each level to avoid mixing of them as we are applying sorted on one horizontal level at a time
        
        PriorityQueue<Pair> parentQ = new PriorityQueue<>((a, b) -> {
            return a.node.val - b.node.val;
        });
        PriorityQueue<Pair> childQ = new PriorityQueue<>((a, b) -> {
            return a.node.val - b.node.val;
        });
        
        int x = Math.abs(leftWidth);
        parentQ.add(new Pair(root, x));
        
        while(parentQ.size() > 0) {
            int size = parentQ.size();
            
            while(size-- > 0) {
                Pair p = parentQ.remove();
                    
                arr.get(p.width).add(p.node.val);
                
                if(p.node.left != null) 
                    childQ.add(new Pair(p.node.left, p.width - 1));
                    
                if(p.node.right != null) 
                    childQ.add(new Pair(p.node.right, p.width + 1));
            }
            
            PriorityQueue<Pair> temp = parentQ;
            parentQ = childQ;
            childQ = temp;
        }
        
        return arr;
    }
    
    // Time complexity = O(N.logN)
    // Space complexity = O(N) 
}