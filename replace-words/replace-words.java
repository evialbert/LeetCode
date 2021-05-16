class Solution {
public String replaceWords(List<String> dictionary, String sentence) {
    if(sentence == null || sentence.length() == 0)
    {
        return "";
    }
    
    String[] strArr = sentence.split(" ");
    
    StringBuilder sb = new StringBuilder();
    
    for(int i = 0; i < strArr.length; i++)
    {
        String val = findRoot(strArr[i], dictionary);
        
        sb.append(val).append(" ");
    }
    
    return sb.toString().trim();
}

String findRoot(String val, List<String> dictionary)
{
    String result = val;
    int i = 0;
    while(i < result.length())
    {
        val = result.substring(0,i);
        if(!dictionary.contains(val))
        {
            i++;
        }
        else
        {
            return val;
        }
    }
    
    return result;
}
}