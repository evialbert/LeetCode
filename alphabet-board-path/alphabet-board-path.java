class Solution {
    public String alphabetBoardPath(String target) {
        StringBuffer result = new StringBuffer();
        //Create a map which stores row , col index of each alphabet starting from a as 0, 0
        Map<Character, int[]> map = new HashMap<Character, int[]>();
        int row = 0;
        int col = 0;
        for(int i = 1; i <= 26; i++) { //Iterate for all 26 characters
            col = (i - 1) % 5;
            map.put(((char)(i + 96)), new int[] {row, col}); //Add 96 to get ASCII to char of small case
            if(i % 5 == 0) ++row; //Increment row 
        }
        int[] curr = {0, 0}; //Starting position of pointer
        for(char c : target.toCharArray()) { //For each string character
            int[] dest = (c == 'z' && curr[0] != 5 && curr[1] != 0) ? map.get('u') : map.get(c); //z needs special handling as it can be reached from u only
            while(curr[0] != dest[0]) {
                if(curr[0] < dest[0]) {
                    curr[0] += 1;
                    result.append('D');
                }
                else {
                    curr[0] -= 1;
                    result.append('U');
                }
            }
            while(curr[1] != dest[1]) {
                if(curr[1] < dest[1]) {
                    curr[1] += 1;
                    result.append('R');
                }
                else {
                    curr[1] -= 1;
                    result.append('L');
                }
            }
            if(c == 'z' && curr[0] == 4 && curr[1] == 0) { //If we need to reach z and we are at u then do this step
                curr[0] += 1;
                result.append('D');
            }
            result.append('!');
        }
        return result.toString();
    }
}