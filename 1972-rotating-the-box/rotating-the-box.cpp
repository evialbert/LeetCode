class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> verticalGrid(boxGrid[0].size(), vector<char>(boxGrid.size(), '.'));
        for (int i = 0; i < boxGrid.size(); i ++) {
            int stone_num = 0;
            int vertical_i = boxGrid.size() - 1 - i;
            for (int j = 0; j < boxGrid[0].size(); j ++) {
                if (boxGrid[i][j] == '#') {
                    stone_num ++;
                } else if (boxGrid[i][j] == '*') {
                    verticalGrid[j][vertical_i] = '*';
                    int m = j - 1;
                    while (stone_num > 0) {
                        verticalGrid[m][vertical_i] = '#';
                        m --;
                        stone_num --;
                    }
                }
            }

            int m = boxGrid[0].size() - 1;
            while (stone_num > 0) {
                verticalGrid[m][vertical_i] = '#';
                m --;
                stone_num --;
            }
        }

        return verticalGrid;
    }
};