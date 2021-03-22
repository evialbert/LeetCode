class Solution {
    public static boolean isHexDigit(char c) {
        return (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9');
    }
    public String validIPAddress(String IP) {
        int currIpV4Token = 0;
        int tokenSt = -1;
        boolean stillValidForIpV4 = true;
        int tokenCount = 1;
        for(int i = 0; i < IP.length(); ++i) {
            char c = IP.charAt(i);
            if(Character.isDigit(c) && stillValidForIpV4) {
                int d = c - '0';
                if(tokenSt == -1) {
                    tokenSt = i; //Setting the start of current token
                }
                if(i > tokenSt && currIpV4Token == 0) { //The case with the leading zero
                    stillValidForIpV4 = false;
                    continue;
                }
                
                currIpV4Token = currIpV4Token * 10 + d;

                if(currIpV4Token > 255 ) {
                    stillValidForIpV4 = false;
                }
            }
            else if(isHexDigit(c)) {
                stillValidForIpV4 = false; //If we any non digit hex char, ruling out the case for IPV4
                if(tokenSt == -1) {
                    tokenSt = i;//Setting the start of current token
                }
                if(i-tokenSt > 3) {
                    return "Neither";
                }
            }
            else if(c=='.'){
                if(tokenSt == -1) { // Case when there was no digit before .
                    return "Neither"; 
                }
                if(!stillValidForIpV4) { //If the IP is already ruled out for IPV4, dot should not be allowed further
                    return "Neither";
                }
                if(tokenCount == 4) { //So far a valid IPV4, but ruled out as we encounter extra fourth dot
                    return "Neither";
                }
                currIpV4Token =0; //resetting the current token to zero for parsing the new token for potential IPV4
                tokenSt = -1; // Marking the end of the token so that we can start scanning for next token
                ++tokenCount;
            }
            else if(c==':') {
                if(tokenSt == -1) { // Case when there was no digit before :
                    return "Neither"; 
                }
                if(tokenCount == 8) { //So far a valid IPV6, but ruled out as we encounter extra eighth colon
                    return "Neither";
                }
                stillValidForIpV4 = false; //If we encounter colon, ruling out the case for IPV4
                tokenSt = -1; // Marking the end of the token so that we can start scanning for next token
                ++tokenCount;
            }
            else {
                return "Neither";
            }
        }
        
        if(stillValidForIpV4 && tokenCount == 4 && tokenSt != -1) {
            return "IPv4";
        }
        if(!stillValidForIpV4 && tokenCount == 8 && tokenSt != -1) {
            return "IPv6";
        }
        return "Neither";
    }

}