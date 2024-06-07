class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st;
        for (auto word : dictionary)
            st.insert(word);

        string ans = "";
        int n = sentence.length();
        int i = 0;

        while (i < n) {
            string s = "";
            bool replaced = false;
            while (i < n && sentence[i] != ' ' && !replaced) {
                s += sentence[i];
                if (st.count(s)) {
                    ans += s + " ";
                    replaced = true;
                } else
                    i++;
            }

            if (!replaced)
                ans += s + " ";

            while (i < n && sentence[i] != ' ')
                i++;
            i++;
        }

        ans.pop_back();
        return ans;
    }
};