class Solution
{
public:
    long long matrixSumQueries(int n, vector<vector<int>> &q)
    {
        unordered_set<int> row, col;
        int nrow = n, ncol = n;
        long long int sum = 0;
        for (int i = q.size() - 1; i >= 0; i--)
        {
            int type = q[i][0];
            int indx = q[i][1];
            int val = q[i][2];
            if (type == 0 && row.find(indx) == row.end())
            {
                sum += (ncol * val);
                row.insert(indx);
                nrow--;
            }
            else if (type == 1 && col.find(indx) == col.end())
            {
                sum += (nrow * val);
                col.insert(indx);
                ncol--;
            }
        }
        return sum;
    }
};