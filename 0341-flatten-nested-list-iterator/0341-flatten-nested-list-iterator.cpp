/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>nums; //store values in this vector
    int pos = -1; //for the current position of vector
    NestedIterator(vector<NestedInteger> &nestedList) {
        convert(nestedList);
        pos = 0;
    }
    void convert(vector<NestedInteger>&lis){
        for(auto i:lis){
            if(i.isInteger()) nums.push_back(i.getInteger()); // these function already defined in the NestedInteger class
            else{
                convert(i.getList()); // calling recursion
            }
        }
    }
    
    int next() {
        return nums[pos++]; //return the current pointing value
    }
    
    bool hasNext() {
        return pos < nums.size(); //return whether next value is there or not.
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */