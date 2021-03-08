class Solution {
    public boolean validUtf8(int[] data) {
        
        int m = data.length, i = 0, j, x, n;
        
        while (i < m)
        {
            // Find the position of the fist '0' in the starting byte
            for (j = 7; j >= 3; j--)
            {
                x = (1 << j);
        
                if ((data[i] & x) == 0)
                    break;
            }
            
            if (j == 2 || j == 6) // Unqualified starting byte, e.g., (11111xxx) and (10xxxxxx)
                return false;
            else if (j == 7) // 1-byte
                i++;
            else
            {
                n = 7 - j; // n-byte
                
                if (m - i < n) // Not enough remaining bytes
                    return false;
                
                i++;
                
                // Detect if the remaining bytes start with "10"
                for (int k = 0; k < n-1; k++)
                {
                    x = (1 << 7);
            
                    if ((data[i] & x) != x)
                        return false;

                    x = (1 << 6);

                    if ((data[i] & x) != 0)
                        return false;
                    
                    i++;
                }
            }
        }
        
        return true;
    }
}