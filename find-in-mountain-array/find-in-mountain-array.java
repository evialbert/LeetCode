/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {        
        int len = mountainArr.length();
        int peak = getPeak(mountainArr, 0, len - 1);
        if(target > mountainArr.get(peak)) return -1;
        int left = binarySearchAsc(target, mountainArr, 0, peak);
        if(left != -1)  return left;
        return binarySearchDesc(target, mountainArr, peak + 1, len - 1);
    }
    
    // function to find Peak in the Mountain
    public int getPeak(MountainArray mArr, int start, int end) {       
        int mid = (start + end) / 2;
        int center = mArr.get(mid);
        int left = mArr.get(mid - 1);
        int right = mArr.get(mid + 1);
        if(center > left && center > right) return mid;
        if(center < right) 
            return getPeak(mArr, mid + 1, end);
        else
            return getPeak(mArr, start, mid);
    }
    
    // Binary Search to find target in sorted arrary in ascending order
    public int binarySearchAsc(int target, MountainArray mArr, int start, int end) {        
        if(end < start) return -1;
        int mid = (start + end) / 2;
        int midval = mArr.get(mid);
        if(midval == target) return mid;
        //if(start == end) return -1; // only 1 element and it is not target
        if(target < midval) 
            return binarySearchAsc(target, mArr, start, mid - 1);
        else
           return binarySearchAsc(target, mArr, mid + 1, end); 
    }
    
     // Binary Search to find target in sorted arrary in descending order
    public int binarySearchDesc(int target, MountainArray mArr, int start, int end) {        
        if(end < start) return -1;
        int mid = (start + end) / 2;
        int midval = mArr.get(mid);
        if(midval == target) return mid;
        //if(start == end) return -1; // only 1 element and it is not target
        if(target > midval) 
            return binarySearchDesc(target, mArr, start, mid - 1);
        else
           return binarySearchDesc(target, mArr, mid + 1, end); 
    }
}