class Solution {
    public String reorderSpaces(String text) {
        List<String> words = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int spaces = 0;
        while(i < text.length())
        {
            if(text.charAt(i)==' ')
            {
                if(sb.length()>0)
                {
                    words.add(sb.toString());
                    sb.setLength(0);
                }
                
                while(i < text.length() && text.charAt(i)==' ')
                {
                    spaces++;
                    i++;
                }
            }
            else
            {
                sb.append(text.charAt(i));
                if(i==text.length()-1)
                {
                    words.add(sb.toString());
                }
                i++;
            }
        }
        
        int div = words.size() == 1 ? 0 : spaces/(words.size()-1);
        int rem = words.size() == 1 ? spaces : spaces%(words.size()-1);
        StringBuilder res = new StringBuilder();
        for(i = 0; i < words.size(); i++)
        {
            res.append(words.get(i));
            if(i==words.size()-1)
            {
                for(int j = 0; j < rem; j++)
                {
                    res.append(' ');
                }
            }
            else
            {
                for(int j = 0; j < div; j++)
                {
                    res.append(' ');
                }
            }
        }
        
        return res.toString();
    }
}