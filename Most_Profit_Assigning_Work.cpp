class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxDiff = *max_element(difficulty.begin(),difficulty.end());
        vector<int> maxprofit_to_difficulty(maxDiff+1,0);

        for(int i=0;i<difficulty.size();i++){
            maxprofit_to_difficulty[difficulty[i]]=max(maxprofit_to_difficulty[difficulty[i]],profit[i]);
        }
        for(int i=1;i<=maxDiff;i++){
            maxprofit_to_difficulty[i]=max(maxprofit_to_difficulty[i],maxprofit_to_difficulty[i-1]);
        }
        int totalProfit=0;
        for(int ability:worker){
            if(ability>maxDiff){
                totalProfit += maxprofit_to_difficulty[maxDiff];
            }else{
                totalProfit += maxprofit_to_difficulty[ability];
            }
        }
        return totalProfit;
    }
};