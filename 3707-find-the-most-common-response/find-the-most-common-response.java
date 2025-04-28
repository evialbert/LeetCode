class Solution
{
    public String findCommonResponse(List<List<String>> responses)
    {
        HashMap<String,Integer> h = new HashMap<>();
        HashSet<String> s = new HashSet<>();

        String res = "";
        int max = 0;
        int curr;
        
        for(List<String> r : responses)
        {
            s.clear();
            s.addAll(r);

            for(String t : s)
            {
                curr = 1+h.getOrDefault(t,0);
                h.put(t,curr);

                if(curr>max || (curr==max && !t.equals(res) && t.compareTo(res)<0))
                {
                    max = curr;
                    res = t;
                }
            }
        }

        return res;
    }
}