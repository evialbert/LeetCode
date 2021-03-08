/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    char[] chars;
    int at = 0;
    public NestedInteger deserialize(String s) {
        chars = s.toCharArray();
        return parseNestedInteger();
    }
    
    NestedInteger parseNestedInteger() {
        if (chars[at] == '[') {
            // parse NestedInteger
            NestedInteger dest = new NestedInteger();
            while(chars[at] != ']') {
                // move to next
                at++;
                if (chars[at] == ']') {
                    // empty NestedInteger
                    break;
                }
                // parse and add into list
                NestedInteger val = parseNestedInteger();
                if (dest.getInteger() == null && dest.getList() == null && val.isInteger()) {
								    // if first is Integer
                    dest.setInteger(val.getInteger());
                } else {
                    dest.add(val);
                }
            }
            // move to next
            at++;
            return dest;
        } else {
            // parse Integer
            boolean nagtive = false;
            int val = 0;
            if (chars[at] == '-') {
                // read flag
                nagtive = true;
                at++;
            }
            while(at < chars.length && chars[at] != ',' && chars[at] != ']') {
                // add value
                val *= 10;
                val += (chars[at] - '0');
                at++;
            }
            return new NestedInteger(nagtive ? -val : val);
        }
    }
    
}