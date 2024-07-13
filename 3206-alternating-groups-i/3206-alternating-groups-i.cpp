class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        int n = colors.size();

        for(int i=2;i<n;i++)
        {
            if(colors[i] != colors[i-1] && colors[i-1] != colors[i-2])
            {
                count++;
            }
        }
        return count;
    }
};