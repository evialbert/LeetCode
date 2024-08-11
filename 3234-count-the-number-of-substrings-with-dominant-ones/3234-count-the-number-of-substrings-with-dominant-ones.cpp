class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int n=s.length();
vector<int>cummSum(n,0);
cummSum[0]=s[0]-'0';
for(int i=1;i<n;i++){
    cummSum[i]=cummSum[i-1]+(s[i]-'0');
}

for(int i=0;i<n;i++){
for(int j=i;j<n;j++){

int oneCnt= i>0 ?cummSum[j]-cummSum[i-1]:cummSum[j];
int zeroCnt=(j-i+1)-oneCnt;

if((zeroCnt*zeroCnt)>oneCnt){
    int diff=(zeroCnt*zeroCnt)-oneCnt;
    j=j+(diff-1);

}

if((zeroCnt*zeroCnt)<=oneCnt){
ans++;

if((zeroCnt*zeroCnt)<oneCnt){
int diff=sqrt(oneCnt)-zeroCnt;

int nextJ=j+diff;
if(nextJ>=n)
ans=ans+(n-j-1);
else
ans=ans+diff;

j=nextJ;
}

}



}

}

        return ans;
    }
};