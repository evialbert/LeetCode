class Solution {
    public long specialPalindrome(long n) {
        if(n==0) return 1;
        int dig = (int) Math.floor(Math.log10(n)) + 1;
        ArrayList<Long> nth = perm(dig);
        ArrayList<Long> n1th = perm(dig+1);
        return bs(n , nth) == -1 ? bs(n , n1th) : bs(n , nth);
    }
    public ArrayList<Long> perm(int n){
        //take all the candidates
        ArrayList<Integer> even_set = new ArrayList<>();
        ArrayList<Integer> odd_set = new ArrayList<>();
            for(int i=1;i<=Math.min(n , 9);i++){ 
                if((i%2) != 0) odd_set.add(i);
                else even_set.add(i);
            }
        if((n%2) != 0){
            //odd case
            return create_perm(odd_set , even_set , n);
        }
        else{
            //even case
            return create_perm(null , even_set , n);
        }
    }
    public ArrayList<Long> create_perm(ArrayList<Integer>odd_set  , ArrayList<Integer>even_set , int n ){
        int limit = n/2 , val = -1;
        ArrayList<Long> res = new ArrayList<>();
        if(odd_set == null){
            int len = even_set.size();
            for(int mask=1;mask<(1<<len);mask++){
                ArrayList<Integer> curr_perm = new ArrayList<>();
                for(int i=0;i<len;i++){
                    if(((1 << i) & mask) != 0){
                        int num = even_set.get(i);
                        for(int count=0;count<num/2;count++) curr_perm.add(num);
                    }
                }
                if(curr_perm.size() == limit) res.addAll(process(curr_perm , val));
                curr_perm = new ArrayList<>();
            }
        }
        else{
            for(int x : odd_set){
                 ArrayList<Integer> papa = new ArrayList<>();
                 for(int j=0;j<(x/2);j++) papa.add(x);
                 
            int len = even_set.size();
            for(int mask=0;mask<(1<<len);mask++){
                ArrayList<Integer> curr_perm = new ArrayList<>(papa);
                for(int i=0;i<len;i++){
                    if(((1 << i) & mask) != 0){
                        int num = even_set.get(i);
                        for(int count=0;count<num/2;count++) curr_perm.add(num);
                    }
                }
                if(curr_perm.size() == limit) res.addAll(process(curr_perm,x));
                curr_perm = new ArrayList<>();
            }
            }
        }
        return res;
    }
    ArrayList<String> combinations ;
    public ArrayList<Long> process(ArrayList<Integer> list , int val){
        int n = list.size();
        ArrayList<Long> ans = new ArrayList<>(); 
        combinations = new ArrayList<>();
        combi(list);
        if(val != -1){
            for(int i=0;i<combinations.size();i++){
                combinations.set(i , combinations.get(i)+val);
            }
        }
        for(int i=0;i<combinations.size();i++){
             String str = combinations.get(i);
             int start = str.length()-1;
             if(val != -1) start--;
             for(int j=start;j>=0;j--){
                str += str.charAt(j);
             }
             ans.add(Long.parseLong(str));
        }
        return ans;
    
    }
    public void combi(ArrayList<Integer> list){
        String curr = "";
        Set<Integer> vis = new HashSet<>();
            for(int i=0;i<list.size();i++){   
                vis.add(i);
                create_comb(list , vis , curr+list.get(i));
                vis.remove(i);
            }
            
     }
     public void create_comb(ArrayList<Integer> list , Set<Integer> vis , String curr){
        if(curr.length() == list.size()){
            combinations.add(curr);
            return;
        }
        for(int i=0;i<list.size();i++){
            if(!vis.contains(i)){
                vis.add(i);
                create_comb(list , vis , curr+list.get(i));
                vis.remove(i);
            }
        }
     }



    public long bs(long n , ArrayList<Long> list){
        Collections.sort(list);
        int res = -1;
        int left = 0 , right = list.size() -1;
        while(left <= right){
            int mid = left + (right - left) / 2 ;
            if(list.get(mid) <= n) {
                left = mid+1;
            }
            else{
                res = mid;
                right = mid-1;
            }
        }
        return res != -1 ? list.get(res) : res; 
    }
}