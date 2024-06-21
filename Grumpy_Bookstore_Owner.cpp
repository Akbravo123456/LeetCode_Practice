class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ini_sat =0;
        int max_extra_sat=0;
        int curr_window_sat=0;

        for(int i=0;i<customers.size();i++){
            if(grumpy[i] == 0){
                ini_sat +=customers[i];
            }else if(i<minutes){
                curr_window_sat +=customers[i];
            }
        }
        max_extra_sat=curr_window_sat;
        for(int i=minutes;i<customers.size();i++){
            curr_window_sat +=customers[i]*grumpy[i];
            curr_window_sat -=customers[i-minutes]*grumpy[i-minutes];
            max_extra_sat =max(max_extra_sat,curr_window_sat);
        }
        return ini_sat+max_extra_sat;
    }
};