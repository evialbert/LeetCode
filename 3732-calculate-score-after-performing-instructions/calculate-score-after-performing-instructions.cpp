class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        long long result = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i >= 0 && i < n; ++i) {
            if (visited[i]) break;
            int j = i;
            if (instructions[i] == "jump") {
                j += values[j] - 1;
            } else {
                result += values[j];
            }
            visited[i] = true;
            i = j;
        }

        return result;
    }
};