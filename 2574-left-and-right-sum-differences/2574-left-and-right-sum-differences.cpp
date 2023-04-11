class Solution {
public:

    vector<int> leftRigthDifference(vector<int>& nums) {
		
        int leftsum=0;
        int rightsum=0;
		
        for(int i=0;i<nums.size();i++){
            rightsum+=nums[i];
        }
		
        vector<int> answer;
		
        for(int i=0;i<nums.size();i++){
            rightsum-=nums[i];
            int j=abs(leftsum-rightsum);
            answer.push_back(j);
            leftsum+=nums[i];
        }
		
        return answer;
    }
};