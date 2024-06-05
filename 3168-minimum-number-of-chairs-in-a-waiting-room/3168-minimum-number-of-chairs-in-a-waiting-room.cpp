class Solution {
public:
    int minimumChairs(string s) {
        int currentOccupied = 0;
        int maxChairs = 0;

        for(char c : s)
        {
            if(c == 'E')
            {
                currentOccupied++;
            }
            else if(c == 'L')
            {
                currentOccupied--;
            }
            if(currentOccupied > maxChairs)
            {
                maxChairs = currentOccupied;
            }
        }
    return maxChairs;
}

};