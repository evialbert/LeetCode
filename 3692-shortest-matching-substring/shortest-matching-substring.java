class Solution {
    public int shortestMatchingSubstring(String s, String p) {

        int minLen = Integer.MAX_VALUE;
        String ar[] = p.split("\\*");
        int arlen = ar.length;
        if (arlen == 0) {
            return 0;
        }

        String temp = p.replace("*", "");
        
        if (s.indexOf(temp) != -1) {
            return temp.length();
        }
        
        
        int f = s.indexOf(ar[0]);
        while (f != -1) {
            int shortLen = Integer.MAX_VALUE;
            if (arlen > 1) {
                int sec = s.indexOf(ar[1], f + ar[0].length());
                while (sec != -1) {
                    if (ar[0].length()==0) {
                        f=sec;
                    }
                    if (arlen > 2) {
                        int third = s.indexOf(ar[2], sec + ar[1].length());
                        if (third != -1) {
                            if (ar[0].length()==0 && ar[1].length()==0) {
                                f=third;
                            }
                            shortLen = third + ar[2].length() - f;
                            minLen = Math.min(shortLen, minLen);
                            if (minLen == p.length()-2) {
                                return minLen;
                            }
                            if (minLen == Integer.MAX_VALUE) {
                                return -1;
                            }
                        }
                    } else {
                        shortLen = sec + ar[1].length() - f;
                        minLen = Math.min(shortLen, minLen);
                    }
                    if (minLen == p.length()-2) {
                        return minLen;
                    }
                    if (ar[1].length()==0) {
                        sec = -1;
                    } else {
                        sec = s.indexOf(ar[1], sec+1);
                    }
                    if (minLen == Integer.MAX_VALUE) {
                        return -1;
                    }
                }
            } else {
                shortLen = f + ar[0].length() - f;
                minLen = Math.min(shortLen, minLen);
            }
            minLen = Math.min(shortLen, minLen);
            if (minLen == p.length()-2) {
                return minLen;
            }
            if (ar[0].length()==0) {
                f = -1;
            } else {
                f = s.indexOf(ar[0], f+1);
            }
            if (minLen == Integer.MAX_VALUE) {
                return -1;
            }
        }

        if (minLen == Integer.MAX_VALUE) {
            return -1;
        }

        return minLen;
        
    }
}