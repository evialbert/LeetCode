class Solution
{
    public String evaluate(String s, List<List<String>> knowledge)
    {
        int index=0;
        StringBuilder result= new StringBuilder();
        HashMap<String,String> map= new HashMap<>();
        for(List<String> list: knowledge)
            map.put(list.get(0), list.get(1));
        for (int i = 0; i < s.length(); i++)
        {
            if (s.charAt(i)=='(')
            {
                result.append(s.substring(index, i));
                index=i+1;
            }
            else if (s.charAt(i)==')')
            {
                result.append(map.getOrDefault(s.substring(index, i), "?"));
                index=i+1;
            }
        }
        result.append(s.substring(index));
        return result.toString();
    }
}