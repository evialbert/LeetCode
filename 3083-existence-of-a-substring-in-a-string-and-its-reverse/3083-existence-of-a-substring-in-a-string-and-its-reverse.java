class Solution
{
    public boolean isSubstringPresent(String s)
    {
        int l = s.length();
        
        HashSet<String> f = new HashSet<>(l);
        HashSet<String> r = new HashSet<>(l);

        String g;

        for(int i=0; i<l-1; i++)
        {
            if(s.charAt(i)==s.charAt(i+1))
                return true;
            
            g = new String(new char[]{s.charAt(i),s.charAt(i+1)});

            if(r.contains(g))
                return true;

            f.add(g);

            g = new String(new char[]{s.charAt(i+1),s.charAt(i)});

            if(f.contains(g))
                return true;

            r.add(g);
        }

        return false;
    }
}