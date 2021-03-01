/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
//Use a queue since it is a first in first out structure
public class NestedIterator implements Iterator<Integer> {
    Queue<Integer> q;
    public NestedIterator(List<NestedInteger> nestedList) {
        q = new LinkedList<>(); //create a new linked list to pass in the list of integers
        addAll(nestedList);
    }
    
    public void addAll(List<NestedInteger> nestedList) {
        for(NestedInteger i : nestedList) {
            //now we check if it is a nested list or it is an integer only
            if(i.isInteger()) {
                q.offer(i.getInteger());
            }
            else {
                addAll(i.getList()); // if this is a list then we
            }
        }
    }

    @Override
    public Integer next() {
      return !q.isEmpty() ? q.poll() : -1; //poll or else return -1
    }

    @Override
    public boolean hasNext() {
        return !q.isEmpty(); //Return true if queue is not empty
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */