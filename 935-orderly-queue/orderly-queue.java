class Solution {
    public String orderlyQueue(final String s, final int k) {
        if(k > 1) {
            final char[] arr = s.toCharArray();

            Arrays.sort(arr);

            return new String(arr);
        }

        String result = s;

        for(int i = 0; i < s.length(); ++i) {
            final String tmp = s.substring(i) + s.substring(0, i);
            
            if(result.compareTo(tmp) > 0)
                result = tmp;
        }

        return result;
    }
}