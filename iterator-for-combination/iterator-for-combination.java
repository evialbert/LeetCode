class CombinationIterator {
    
    ArrayList<String> arr = new ArrayList<>();
    int count = 0;
    
    public CombinationIterator(String characters, int combinationLength) {
        permutation(characters,new StringBuilder(),0,combinationLength);
    }
    
    public String next() {
        return arr.get(count++);
    }
    
    public boolean hasNext() {
        return count < arr.size();
    }
    
    public void permutation(String s,StringBuilder sb,int idx,int n){
        if(sb.length() == n){
            arr.add(sb.toString());
            return;
        }
        for(int i = idx ; i < s.length();i++){
            sb.append(s.charAt(i));
            permutation(s,sb,i+1,n);
            sb.deleteCharAt(sb.length()-1);
        }
        return;
    }
}
