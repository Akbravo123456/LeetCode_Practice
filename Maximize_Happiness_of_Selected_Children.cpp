class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long total=0;
        for(int i=0;i<k;i++){
            int curr=happiness[i];
            int happinessIfSelected = curr - i;
            if(happinessIfSelected >=0){
            total+=happinessIfSelected;
            }else{
                break;
            }
        }
        return total;
    }
};