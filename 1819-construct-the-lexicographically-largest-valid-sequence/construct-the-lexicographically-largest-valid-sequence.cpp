class Solution {
public:
    bool construct(int index , int n , vector<int> &result , vector<bool> &used){
        if(index >= result.size()){
            return true;
        }
        if(result[index] != -1){
            return construct(index+1 , n , result , used);
        }
        else{
            for(int num=n ; num>=1 ; num--){
                if(used[num] == true){
                    continue;
                }
                else{
                    used[num] = true;
                    result[index] = num;

                    if(num == 1){
                        if(construct(index+1 , n , result , used)){
                            return true;
                        }
                    }
                    else{
                        int secondIndex = result[index] + index;
                        if(secondIndex < result.size() && result[secondIndex] == -1){
                            result[secondIndex] = num;
                            if(construct(index+1 , n , result , used) == true){
                                return true;
                            }
                            result[secondIndex] = -1;
                        }
                    }
                    used[num] = false;
                    result[index] = -1;
                }
            }
        }
        return false;

    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1 ,-1);
        vector<bool> used(n+1,false);
        construct(0 , n , result , used);
        return result;
    }
};