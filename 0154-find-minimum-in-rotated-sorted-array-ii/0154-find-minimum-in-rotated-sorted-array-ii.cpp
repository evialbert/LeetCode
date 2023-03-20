class Solution {
public:
    int findMin(vector<int>& A) {
        int n = A.size();
        if (A[0] < A[n - 1]) // This means array is not rotated
            return A[0];
        int l = 0, r = n - 1;
        return calc(l, r, A);
    }
    int calc(int l, int r, vector<int>&A)
    {
        if (l >= r)
            return A[l];
        int mid = l + (r - l) / 2;

        if (A[mid] < A[0])      // If A[mid] is less than first element, minimum lies to the left of mid
            return calc(l, mid, A);

        else if (A[mid] > A[0]) // If A[mid] is greater than first element, minimum lies to the right of mid
            return calc(mid + 1, r, A);

        else                    // If A[mid] is equal to first element, minimum can lie on either side of mid
            return min(calc(l, mid, A), calc(mid + 1, r, A));

    }
};   