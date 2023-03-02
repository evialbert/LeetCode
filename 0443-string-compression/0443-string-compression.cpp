class Solution {
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            int k = i;
            while (i + 1 < n and chars[i + 1] == chars[i])
                i++;

            chars[j++] = chars[k];
            int l = i - k + 1;
            if (l != 1)
            {
                string num = to_string(l);
                for (auto n : num)
                    chars[j++] = n;
            }
        }
        return j;
    }
};