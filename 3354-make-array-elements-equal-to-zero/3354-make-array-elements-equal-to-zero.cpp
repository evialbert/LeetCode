class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int len = nums.size(), count =0, sum =0, result =0;
        for( const auto & i : nums)
            sum += i;

        int  left =0, right =0;
        // vector <vector<int>> data(count, vector<int>(2,0));
       
        for( int i =0; i< nums.size(); i++){
            left += nums[i];
            right =sum - left;
            cout<<left <<" "<<right<<endl;
            if ( nums[i] == 0){
                if( abs(right -left) == 0)
                    result +=2;
                else if( abs( right -left) == 1)
                    result +=1;
            }
        }
        return result;

    }
};