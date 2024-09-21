class Solution {

        String target;
        Trie root;
        Integer[] dp;
        public int minValidStrings(String[] words, String target) {
            this.target = target;
            root = new Trie();
            dp = new Integer[target.length()];
            //build Trie
            for(String e : words){
                Trie st = root;
                for(int i=0;i<e.length();i++){
                    if(st.children[e.charAt(i)-'a']==null){
                        st.children[e.charAt(i)-'a'] = new Trie();
                    }

                    st = st.children[e.charAt(i)-'a'];
                }
            }

            int re = recur(0);

            if(re==Integer.MAX_VALUE){
                re = -1;
            }

            return re;
        }

        int recur(int ind){
            if(ind>=target.length()) {
                return 0;
            }

            if(dp[ind]!=null){
                return dp[ind];
            }

            dp[ind]=Integer.MAX_VALUE;
            Trie st = root;
            for(int i=ind; i<target.length(); i++){
                if(st.children[target.charAt(i)-'a']!=null){
                    // recur for every valid prefix
                    st = st.children[target.charAt(i)-'a'];
                    int recResult = recur(i+1);
                    if(recResult!=Integer.MAX_VALUE){
                        dp[ind] = Math.min(dp[ind], 1 + recResult);
                    }
                }else{
                    // prefix is not valid
                    break;
                }
            }

            return dp[ind];
        }

    }

    class Trie{
        Trie[] children;
        Trie(){
            children = new Trie[26];
        }
    }