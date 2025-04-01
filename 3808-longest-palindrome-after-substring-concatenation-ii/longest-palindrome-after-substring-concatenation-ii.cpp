class Solution {
public:
    unordered_map<char, vector<int>> mymap1, mymap2;
    int longestPalindrome(string s, string t) {

        int res =1;

        int n = s.size(), m = t.size();
        //res = max(res, helper(s));
       // res = max(res, helper(t));
        for(int i=0; i<n; i++){
            mymap1[s[i]].push_back(i);
        }
        for(int i=0; i<m; i++){
            mymap2[t[i]].push_back(i);
        }
        if(mymap1.size()==1) res = max(res, n);
        if(mymap2.size()==1) res = max(res, m);
        if(mymap1.size()==1 && mymap2.size()==1){
            if(s[0]==t[0]) return m+n;
            else return max({res, n, m});
        }
        string sp = s;
        sp+=t;
        string sp1 = sp;
        reverse(sp1.begin(), sp1.end());
        if(sp==sp1) return m+n;

        for(int i=0; i<n; i++){
            if(mymap2.find(s[i])!= mymap2.end()){
                res = max(res, 2);
                for(auto it: mymap2[s[i]]){
                    int l = i, r = it, l1 = i, r1 = it;
                    if(i<n-1 || it>0){
                        res = max(res, 3);
                    }
                    while(l>=0 && r<m){
                        if(s[l]==t[r]){
                            l--;
                            r++;
                        }else break;
                    }
                    while(l1<n && r1>=0){
                        if(s[l1]==t[r1]){
                            l1++;
                            r1--;
                        }else break;
                    }
                    int len = (l1-l-1)*2;
                    if(l1<n-1 || r1>0){
                        len++;
                    }
                    res = max(res, len);
                }
            }
            res = max(res, helper4(s, t, i, i,1));
            if(i+1<n && s[i]==s[i+1]){
                res = max(res, 2);
                res = max(res, helper4(s, t, i, i+1,0));
                //cout<<"i2=. "<<i<<"  res2=.   "<<res<<endl;
            }
           // cout<<"i2=. "<<i<<"  res=.   "<<res<<endl;
        }

        for(int i=0; i<m; i++){
            res = max(res, helper5(s, t, i, i,1));
            if(i+1<m && t[i]==t[i+1]){
                res = max(res, helper5(s, t, i, i+1,0));
            }
           // cout<<"i1=. "<<i<<"  res1=.   "<<res<<endl;
        }

        return res;
        
    }
    int helper5(string s, string t, int l, int r, int flag){
        int n = s.size(), m = t.size();
        int res =1; int r4 =0;
        int i = r; int i1 =l;
         while(1){
                if(l>=0 && r<m &&t[l]==t[r]){
                    //cout<<"i =   "<<i<<". l=. "<<l<<". r=. "<<r<<endl;
                    l--;
                    r++;
                   // cout<<"i =   "<<i<<". l=. "<<l<<". r=. "<<r<<endl;
                     res = max(res, r-l-1);
                }else{
                    
                    //res = max(res, r-l-1);
                    if(r==m){
                        r--;
                        l++;
                    }
                    r4 = r;
                    //cout<<"i=. "<<i<<". r4 =  "<<r4<<endl;
                    if(r<m && mymap1.find(t[r])!=mymap1.end()){
                        res = max(res, 2);
                        int l1 =0; int r1 = r4;
                        for(auto it: mymap1[t[r]]){
                            l1 = it;  r1 = r4;
                            if(l1<n-1 || r1>0){
                                res = max(res, 3);
                            }
                            while(l1>=0 && r1<m){
                                if(s[l1]==t[r1]){
                                   
                                    l1--;
                                    r1++;
                                }else break;
                            }
                            //cout<<"r4=. "<<r4<<". r5=. "<<r1<<endl;
                            int len = (r1-i)*2;
                            if(flag) len--;
                            res = max(res, len);
                            
                        }
                     
                    }
                    break;
                }
            }
        return res;

        
        
    }
    int helper4(string s, string t, int l, int r, int flag){
        int n = s.size(), m = t.size();
        int res =1;
        int i =l; int i1 =r;
        //cout<<"l=. "<<i<<". r=.  "<<i1<<".  flag=. "<<flag<<endl;
         while(l>=0 && r<=n){
                if(r<n && s[l]==s[r]){
                    l--;
                    r++;
                    res = max(res, r-l-1);
                }else{
                    //res = r-l-1;
                    if(l>=0 && mymap2.find(s[l])!=mymap2.end()){
                         res = max(res, 2);
                        int r1 =0; int l1 = l;
                        for(auto it: mymap2[s[l]]){
                            r1 = it; l1 = l;
                            if(r1>0 || l<n-1){
                                res = max(res, 3);
                            } 
                            while(l1>=0 && r1<m){
                                if(s[l1]==t[r1]){
                                    l1--;
                                    r1++;
                                }else break;
                            }
                            int len = (i-l1)*2;
                            if(flag) len--;
                           
                            res = max(res, len);
                        }
                        
                    }
                    break;
                }
            }
        return res;

        
        
    }
};