class Solution {
public List<Boolean> camelMatch(String[] queries, String pattern) {
    List<Boolean> result = new ArrayList<>();
    
    for(String word : queries)
    {
        result.add(match(word,pattern)); 
    }
    
    return result;
}

private boolean match(String text, String pattern)
{
    int textIndex = 0;
    int patternIndex = 0;
    
    while(textIndex < text.length())
    {
             if(patternIndex < pattern.length() && text.charAt(textIndex) == pattern.charAt(patternIndex))
        {
            patternIndex++;
        }
        else if(text.charAt(textIndex) >= 'A' && text.charAt(textIndex) <= 'Z')
        {
            return false;
        }
        
        textIndex++;
    }
    
    return (patternIndex == pattern.length());
}
}