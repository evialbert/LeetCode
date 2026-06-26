class Solution {
    public int passwordStrength(String password) {
        // A checklist for all 128 standard keyboard characters
        boolean[] vis = new boolean[128];
        int point = 0;

        for(char ch : password.toCharArray()) {
            // If we have NEVER seen this character before
            if(!vis[ch]) {
                vis[ch] = true; // Mark it as seen

                // Award points based on character type
                if(ch >= 'a' && ch <= 'z') {
                    point += 1;
                } else if(ch >= 'A' && ch <= 'Z') {
                    point += 2;
                } else if(ch >= '0' && ch <= '9') {
                    point += 3;
                } else if(ch == '!' || ch == '@' || ch == '#' || ch == '$') {
                    point += 5;
                }
            }
        }
        return point;
    }
}