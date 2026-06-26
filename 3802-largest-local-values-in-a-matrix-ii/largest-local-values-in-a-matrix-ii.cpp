class Solution {
private:
    vector<int> lg;
    vector<vector<vector<vector<int>>>> st;

    void buildSparseTable(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        lg.resize(max(n, m) + 1);
        for(int i = 2; i < lg.size(); i++) {
            lg[i] = lg[i/2] + 1;
        }

        int Kx = lg[n] + 1;
        int Ky = lg[m] + 1;

        st.assign(Kx, vector<vector<vector<int>>>(
                Ky, vector<vector<int>>(n, vector<int>(m))
            )
        );

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                st[0][0][i][j] = matrix[i][j];
            }
        }

        for(int ky = 1; ky < Ky; ky++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j + (1<<ky) <= m; j++) {
                    st[0][ky][i][j] = max(
                        st[0][ky-1][i][j],
                        st[0][ky-1][i][j + (1 << (ky-1))]
                    );
                }
            }
        }

        for(int kx = 1; kx < Kx; kx++) {
            for(int ky = 0; ky < Ky; ky++) {
                for(int i = 0; i + (1<<kx) <= n; i++) {
                    for(int j = 0; j + (1<<ky) <= m; j++) {
                        st[kx][ky][i][j] = max(
                            st[kx-1][ky][i][j],
                            st[kx-1][ky][i + (1 << (kx-1))][j]
                        );
                    }
                }
            }
        }
    }

    int queryMax(int x1, int y1, int x2, int y2) {
        if(x1 > x2 || y1 > y2) return INT_MIN;

        int kx = lg[x2 - x1 + 1];
        int ky = lg[y2 - y1 + 1];

        int nx = x2 - (1<<kx) + 1;
        int ny = y2 - (1<<ky) + 1;

        return max({
            st[kx][ky][x1][y1],
            st[kx][ky][nx][y1],
            st[kx][ky][x1][ny],
            st[kx][ky][nx][ny]
        });
    }

public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        buildSparseTable(matrix);

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int x = matrix[i][j];
                if(x == 0) continue;

                int minRow = max(0, i-x);
                int maxRow = min(n-1, i+x);
                int minCol = max(0, j-x);
                int maxCol = min(m-1, j+x);

                bool localMax = true;

                int innerMax = queryMax(minRow+1, minCol+1, maxRow-1, maxCol-1);

                if(innerMax > x) localMax = false;

                if(localMax) {
                    for(int col = minCol; col <= maxCol; col++) {
                        // top row
                        if(!(abs(minRow-i) == x && abs(col-j) == x)) {
                            if(matrix[minRow][col] > x) {
                                localMax = false;
                                break;
                            }
                        }

                        // bottom row
                        if(maxRow != minRow &&
                        !(abs(maxRow-i) == x && abs(col-j) == x)) {
                            if(matrix[maxRow][col] > x) {
                                localMax = false;
                                break;
                            }
                        }
                    }
                }

                if(localMax) {
                    for(int row = minRow+1; row < maxRow; row++) {
                        // left col
                        if(matrix[row][minCol] > x) {
                            localMax = false;
                            break;
                        }

                        // right col
                        if(minCol != maxCol &&
                        matrix[row][maxCol] > x) {
                            localMax = false;
                            break;
                        }
                    }
                }

                if(localMax) cnt++;
            }
        }

        return cnt;
    }
};