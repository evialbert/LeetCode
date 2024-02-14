class Solution {
    public int maxPalindromesAfterOperations(String[] words) {
        int[] fre=new int[26];
        int p=0,a=0;
        int n=words.length;
        for(int i=0;i<n;++i){
            char[] ch=words[i].toCharArray();
            for(int j=0;j<ch.length;++j){
                char c=ch[j];
                fre[c-'a']++;
            }
        }
        for(int i=0;i<26;++i){
            if(fre[i]==0)
            continue;
            if((fre[i]%2)!=0)
            a++;
            p+=(fre[i]/2);
           
        }
        Comparator<String> comp=new Comparator<String>(){
            public int compare(String s1,String s2){
                if (s1.length() > s2.length())
                return 1;
                else if (s1.length() < s2.length())
                return -1;
                else
                return 0;
            }
        };
        Arrays.sort(words,comp);
        int c=0;
        for(int i=0;i<n;++i){
            int l=words[i].length();
             int q=l/2;
             if(p<q)
             break;
            if(l%2==0){
                if(p>=q){
                    p-=q;
                    c++;
                }
            }
            else{
                if(a>0){
                    a--;
                    p-=q;
                    c++;
                }
                else if(a==0 && p==q)
                break;
                else if(a==0 && p>q){
                    p-=q;
                    p--;
                    a++;
                    c++;
                }
            }
            
        }
        return c;
    }
}