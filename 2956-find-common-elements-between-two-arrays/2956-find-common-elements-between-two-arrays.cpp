class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0 ;
        int count2 = 0;
        int n = nums1.size() ;
        int m = nums2.size() ;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (nums1[i] == nums2[j]){
                    count1++ ;
                    break ;
                }
            }
        }
        for (int j=0; j<m; j++){
            for (int i=0; i<n; i++){
                if (nums2[j] == nums1[i]){
                    count2++ ;
                    break ;
                }
            }
        }
        vector<int> answer ; 
        answer.push_back(count1) ;
        answer.push_back(count2) ;
        return answer ;
    }
};