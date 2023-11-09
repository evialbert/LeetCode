//Time Complexity : O(N)
//Space Complexity : O(1)

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n_energy = 0;
        int n_exp = 0;
        for(auto x : energy){
            if(initialEnergy <= x){
                n_energy += x-initialEnergy+1;
                initialEnergy += x-initialEnergy+1;
            }
            initialEnergy -= x;
        }
        for(auto x : experience){
            if(initialExperience <= x){
                n_exp += x-initialExperience+1;
                initialExperience += x-initialExperience+1;
            }
            initialExperience += x;
        }
        
        return n_energy+n_exp;
    }
};