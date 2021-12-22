class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        // A minimum of 1 frog is needed
        int minNumberOfFrogs=1;
        int c=0, r=0, o=0, a=0;
        
        // At any point if we notice the letters in the wrong order, we can return -1
        for (char ch: croakOfFrogs.toCharArray()) {
            switch(ch) {
                case 'c':
                    c++;
                    break;
                case 'r':
                    r++;
                    if (r > c) return -1;
                    break;
                case 'o':
                    o++;
                    if (o > r) return -1;
                    break;
                case 'a':
                    a++;
                    if (a > o) return -1;
                    break;
                default:
                    c--;
                    r--;
                    o--;
                    a--;
                    // We want to know the number of croaks that are in progress(which is given by c+1) 
                    // whenever we encounter k. This will give us the minimum number of frogs 
                    // needed. We want to maintain the maximum count of the minimum number of frogs needed
                    // at the end of any croak.
                    if (c>0) minNumberOfFrogs = Math.max(c+1, minNumberOfFrogs);
                    break;
            }
        }
        return c > 0 ? -1 : minNumberOfFrogs;
    }
}