class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> l=new ArrayList<Integer>();
        for(int i=0;i<words.length;i++){
        if(words[i].indexOf(x)!=-1) l.add(i);
        }
        return l;
    }
}