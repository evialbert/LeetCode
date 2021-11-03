class Solution {
    public int trav(String[] words,HashMap<Character,Integer>map,int score[],int index)
    {
        if(index>=words.length)
            return 0;
        int ans=0,s=0,f=1;
        HashMap<Character,Integer>temp=new HashMap<Character,Integer>();
        for(int i=0;i<words[index].length();i++)
        {
            char ch=words[index].charAt(i);
            if(map.containsKey(words[index].charAt(i)))
            {
                s=s+score[ch-97];
                map.put(ch,map.get(ch)-1);
                if(temp.containsKey(ch))
                    temp.put(ch,temp.get(ch)+1);
                else
                    temp.put(ch,1);
                if(map.get(ch)==0)
                    map.remove(ch);
            }
            else
            {
                f=-1;
                break;
            }     
        }
        if(f!=-1)
            ans=s+trav(words,map,score,index+1);
        for(Map.Entry<Character,Integer>c: temp.entrySet())
        {
            if(map.containsKey(c.getKey()))
                map.put(c.getKey(),map.get(c.getKey())+c.getValue());
            else
                map.put(c.getKey(),c.getValue());
        }
        ans=Math.max(ans,trav(words,map,score,index+1));
        return ans;
    }
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        HashMap<Character,Integer>map=new HashMap<Character,Integer>();
        for(int i=0;i<letters.length;i++)
        {
            if(map.containsKey(letters[i]))
                map.put(letters[i],map.get(letters[i])+1);
            else
                map.put(letters[i],1);
        }
        return trav(words,map,score,0);
    }
}