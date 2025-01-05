class Solution
{
public:
    bool hasMatch(const string& s, string& p)
    {
        int asterisk_idx = p.find("*");
        std::string left = p.substr(0, asterisk_idx);
        std::string right = p.substr(asterisk_idx + 1);

        if (left.empty())
        {
            return s.rfind(right) != std::string::npos;
        }

        if (right.empty())
        {
            return s.find(left) != std::string::npos;
        }

        std::size_t ileft = s.find(left);
        std::size_t iright = s.rfind(right);
        if (ileft == std::string::npos || iright == std::string::npos)
        {
            return false;
        }

        return ileft + left.length() <= iright;
    }
};