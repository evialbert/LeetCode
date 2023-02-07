class Solution {
public:
    int digits(int n) {
        int cnt = 0;
        while (n) {
            n /= 10;
            cnt++;
        }
        return cnt;
    }
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        for (int length = 1; length * 2 + 3 < limit; ++length) {
            int cnt = (pow(10, length) - 1);
            int available = cnt * limit;
            available -= 3 * cnt;
            available -= length * cnt;
            for (int i = 1; i <= length; ++i) {
                available -= i * (pow(10, i) - pow(10, i - 1));
            }
            if (available >= n) return generate(message, limit, length);
        }
        
        return {};
    }
    vector<string> generate(string& message, int limit, int length) {
        int n = message.size();
        vector<string> res;
        int index = 0;
        int cnt = 1;
        while (index < n) {
            int remain = limit - 3;
            remain -= digits(cnt);
            remain -= length;
            int extract = min(remain, n - index);
            string temp = message.substr(index, extract) + "<" + to_string(cnt) + "/";
            res.push_back(temp);
            index += extract;
            cnt++;
        }
        string blockCnt = to_string(cnt - 1);
        for (auto& word : res) {
            word += blockCnt + ">";
        }
        return res;
    }
};