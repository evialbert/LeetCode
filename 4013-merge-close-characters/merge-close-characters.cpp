class Solution {
public:
    string mergeCharacters(string s, int k) {
        string arr=s;
        //int n=arr.size();
        for(int step=0;step<100;step++){
            bool check=false;
            for(int i=0;i<arr.size();i++){
                for(int j=i+1;j<arr.size();j++){
                    if(arr[i]==arr[j] && (j-i)<=k){
                        arr.erase(j,1);
                        check=true;
                        break;
                    }
                }
                if(check) break;
            }
            if(!check) break;
        }
        return arr;
    }
};