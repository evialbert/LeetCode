/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    
    public int firstBadVersion(int n) {
        int left = 1, right = n;
        int badVersion = -1;
        while (badVersion == -1) {
            int middle = left + (right-left)/2;
            boolean pre = isBadVersion(middle-1);
            boolean cur = isBadVersion(middle);
            if (!pre && cur) {
                badVersion = middle;
            } else {
                // false true     middle is BadVersion
                // false false    left = middle + 1;
                // true false     x
                // true true      right = middle - 1;
                if (pre) {
                    right = middle-1;
                } else {
                    left = middle + 1;
                }
            }
        }
        return badVersion;
    }
}