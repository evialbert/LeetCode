class Solution {
    public List<Integer> partitionLabels(String s) {
        Map <Character,Integer> last = new HashMap <> ();
        int len = s.length();
        List <Integer> arr = new ArrayList <> ();
		// get last occurrence of each letter
        for (int i=0; i<len; i++)
            last.put(s.charAt(i),i);
        int end=0;
        int start=0;
        for (int i=0; i<len; i++) {
            char ch = s.charAt(i);
			// keep pushing end whenever a character occurs after the present section's end
            if (last.get(ch)>end)
                end = last.get(ch);
			// if we have reached end split and add the section length, move the start
            if (i==end) {
                arr.add(end-start+1);
                start = i+1;
            }
        }
		// add residual section
        if (start<len)
            arr.add(len-start);
        return arr;
    }
}