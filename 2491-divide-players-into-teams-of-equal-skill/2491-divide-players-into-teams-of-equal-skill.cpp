class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(skill.begin(), skill.end());
        
        long long sum = skill[0]+skill[skill.size()-1];
        long long result = skill[0]*skill[skill.size()-1];
        long long left = 1, right = skill.size()-2;
        while(left < right) {
            if(sum != skill[left]+skill[right]) {
                return -1;
            }
            result += skill[left]*skill[right];
            left++;
            right--;
        }
        return result;
    }
};