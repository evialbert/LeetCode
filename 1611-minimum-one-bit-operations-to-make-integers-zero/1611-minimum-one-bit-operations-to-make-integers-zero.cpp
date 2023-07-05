class Solution {
public:
    inline uint cost(uint i) { return (1u << (i + 1)) - 1; }
    int minimumOneBitOperations(uint n) {
        uint dpx = (n & 1) == 1;
        uint dpy = (n & 1) == 0;
        uint i = 1;
        while (n >>= 1 > 0) {
            if (n & 1) {
                uint tdpx = dpy + 1 + cost(i - 1);
                dpy = dpx;
                dpx = tdpx;
            } else {
                dpy = dpy + 1 + cost(i - 1);
            }
            i++;
        }
        return dpx;
    }
};