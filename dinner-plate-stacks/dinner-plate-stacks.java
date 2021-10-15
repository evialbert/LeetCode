class DinnerPlates {
    
    TreeSet<Integer> filledStacks = new TreeSet<>();
    TreeSet<Integer> emptyStacks = new TreeSet<>();
    List<Stack<Integer>> stacks;
    int capacity;
    int count = 0;

    public DinnerPlates(int capacity) {
        this.stacks = new ArrayList<>();
        this.capacity = capacity;
        stacks.add(new Stack<>());
        emptyStacks.add(0);
    }
    
    public void push(int val) {
        int index = emptyStacks.first();
        stacks.get(index).add(val);
        filledStacks.add(index);
        if (stacks.get(index).size() == capacity) {
            emptyStacks.pollFirst();
            stacks.add(new Stack<>());
            emptyStacks.add(stacks.size() - 1);
        }
    }
    
    public int pop() {
        if (filledStacks.isEmpty())
            return -1;
        int index = filledStacks.last();
        return popAtStack(index);
    }
    
    public int popAtStack(int index) {
        if(index >= stacks.size())
            return -1;
        Stack<Integer> stack = stacks.get(index);
        if (stack.isEmpty()) {
            return -1;
        }
        int value = stack.pop();
        if (stack.size() != capacity) {
            emptyStacks.add(index);
        }
        if(stack.isEmpty()) {
            filledStacks.remove(index);
        }
        return value;
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */