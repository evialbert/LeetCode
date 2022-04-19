class FrontMiddleBackQueue {
private final List<Integer> queue;

    public FrontMiddleBackQueue() {
        queue = new ArrayList<>();
    }

    public void pushFront(int val) {
        queue.add(0, val);
    }

    public void pushMiddle(int val) {
        queue.add(queue.size() / 2, val);
    }

    public void pushBack(int val) {
        queue.add(val);
    }

    public int popFront() {
        return queue.isEmpty() ? -1 : queue.remove(0);
    }

    public int popMiddle() {
        return queue.isEmpty() ? -1 : queue.remove((queue.size() - 1) / 2);
    }

    public int popBack() {
        return queue.isEmpty() ? -1 : queue.remove(queue.size() - 1);
    }
}  

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */