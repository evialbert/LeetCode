class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string word(n + m - 1, 'a');
        vector<int> fixed(n + m - 1, 0);

        for (int i = 0; i < n; i++)
            if (str1[i] == 'T') {
                word.replace(i, m, str2);

                for (int j = i; j < i + m; j++)
                    fixed[j] = 1;
            }

        for (int i = 0; i < n; i++) {
            string sub = word.substr(i, m);

            if (str1[i] == 'T') {
                if (sub != str2)
                    return "";
            } 
            else {
                if (sub == str2) {
                    int indx = -1;

                    for (int j = i + m - 1; j >= i; j--) {
                        if (!fixed[j]) {
                            indx = j;
                            break;
                        }
                    }

                    if (indx == -1)
                        return "";

                    word[indx] = 'b';
                }
            }
        }

        return word;
    }
};