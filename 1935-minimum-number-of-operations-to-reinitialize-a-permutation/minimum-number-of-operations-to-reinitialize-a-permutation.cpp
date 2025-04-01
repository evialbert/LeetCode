class Solution {
public:
    int reinitializePermutation(int n) {
        int x, y = 1, ret = 0;
        x = 1;
        do {
            if (x < n / 2) {
                x = 2 * x;
            }
            else {
                int a = (x - n / 2);
                // cout << x << " " << a << " " << x << " " << n/2 << endl;
                x = 2 * a + 1;
            }
            ret++;
        }while (x != y);

        return ret;
    }
};

/*
1 2 4 3 6
2 4 6 8 10
0 1 2 3 4 5 6 7 8 9
0 5 1 6 2 7 3 8 4 9
0 7 5 3 1 8 6 4 2 9
0 8 7 6 5 4 3 2 1 9
0 4 8 3 7 2 6 1 5 9
0 2 4 6 8 1 3 5 7 9
0 1 2 3 4 5 6 7 8 9


0 n/2+0 1 n/2+1 2 n/2+2


*/