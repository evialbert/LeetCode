class Solution {
    public int findLongestChain(int[][] pairs) {
        // base case
        if (pairs.length == 0){
            return 0;
        }
        
        ArrayList<Node> arr = new ArrayList<>();
        for (int i = 0; i< pairs.length; i++){
            Node node = new Node(pairs[i][0], pairs[i][1]);
            arr.add(node);
        }
        
		// sorting the arraylist of objects on basis of the end values
        Collections.sort(arr, new cmp());
        
		// initializing with 1 as the first object of the arraylist is always considered 
        int ans = 1;
        Node prev = arr.get(0);
		// prev maintains the current node pointer
		
        for (int i = 1; i< arr.size(); i++){
            if (arr.get(i).a > prev.b){
                ans++;
                prev = arr.get(i);
            }
        }
        return ans;
    }
}

class Node{
    int a;
    int b;
    public Node(int a, int b){
        this.a = a;
        this.b = b;
    }
}

class cmp implements Comparator<Node>{
    public int compare(Node x, Node y){
        return x.b - y.b;
    }
}