class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        int i = 0;
        
        while (i < words.size())
        {
            const auto result = countLineWords(i, maxWidth, words);

            const bool isLastLine = get<0>(result);
            const auto wordCount = get<1>(result);
            auto remainingSpaces = get<2>(result);

            if (isLastLine || wordCount == 1)
                lines.push_back(generateLine(words, wordCount, maxWidth, i));
            else
            {
                const auto spaces = distributeSpaces(wordCount, remainingSpaces);
                lines.push_back(generateLine(words, wordCount, spaces, i));
            }

            i += wordCount;
        }

        return lines;
    }

private:
    tuple<bool, int, int> countLineWords(const int &i, const int &maxWidth, const vector<string>& words)
    {
        int wordCount = 1;
        int remainingSpaces = maxWidth - words[i].length();
        auto j = i+1;

        while (j < words.size() && remainingSpaces >= words[j].length() + 1)
        {
            ++wordCount;
            remainingSpaces -= words[j].length() + 1;
            ++j;
        }
        return std::make_tuple(j == words.size(), wordCount, remainingSpaces);
    }

    vector<int> distributeSpaces(const int &wordCount, int &remainingSpaces)
    {
        vector<int> spaces(wordCount - 1, 1);
        auto spaceIdx = 0;
        
        while (remainingSpaces > 0)
        {
            ++spaces[spaceIdx];
            spaceIdx = (spaceIdx + 1) % spaces.size();
            --remainingSpaces;
        }
        
        return spaces;
    }

    string generateLine(const vector<string>& words, const int &wordCount, const int &maxWidth, int &i)
    {
        stringstream ss;

        int j = 0;
        ss << words[i + j];
        ++j;

        for ( ; j < wordCount; ++j)
            ss << " " << words[i + j];

        string padding(maxWidth - ss.str().length(), ' ');
        ss << padding;
        return ss.str();
    }

    string generateLine(const vector<string>& words, const int &wordCount, const vector<int> &spaces, int &i)
    {
        stringstream ss;

        int j = 0;
        ss << words[i + j];
        ++j;

        for ( ; j < wordCount; ++j)
        {
            string padding(spaces[j-1], ' ');
            ss << padding << words[i + j];
        }

        return ss.str();
    }
};