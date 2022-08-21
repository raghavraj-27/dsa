class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int count = 0;
        for(int i=0; i<energy.size(); i++) {
            int val = energy[i];
            if(val < initialEnergy) {
                initialEnergy -= val;
            } else {
                count = (val - initialEnergy + 1) + accumulate(energy.begin()+i+1, energy.end(), 0);
                cout<<count<<endl;
                break;
            }
        }
        
        for(int i=0; i<experience.size(); i++) {
            int val = experience[i];
            
            if(val >= initialExperience) {
                count += val - initialExperience + 1;
                initialExperience = val+1;
            } //else {
                initialExperience += val;
            //}
        }
        
        return count;
    }
};