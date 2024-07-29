class Solution {
public:
    int numTeams(vector<int>& rating){
        int max_rating = 0;
        for (int rat : rating){
            max_rating = max(max_rating,rat);
        }
        
        vector<int> left(max_rating+1,0);
        vector<int> right(max_rating+1,0);
        
        for (int rat : rating) {
            updateBIT(right, rat,1);
        }
        
        int teams = 0;
        for (int curr_rat : rating){
            updateBIT(right,curr_rat,-1);
            
            int smallerRatingsLeft = getPrefixSum(left, curr_rat - 1);
            int smallerRatingsRight = getPrefixSum(right, curr_rat - 1);
            int largerRatingsLeft = getPrefixSum(left, max_rating) - getPrefixSum(left, curr_rat);
            int largerRatingsRight = getPrefixSum(right, max_rating) - getPrefixSum(right, curr_rat);
            
            teams +=(smallerRatingsLeft * largerRatingsRight);
            teams +=(largerRatingsLeft * smallerRatingsRight);
            
            updateBIT(left,curr_rat,1);
        }
        return teams;
    }

    void updateBIT(vector<int>& BIT,int index,int value){
        while(index<BIT.size()) {
            BIT[index] +=value;
            index +=index & (-index);
        }
    }

    int getPrefixSum(vector<int>& BIT,int index){
        int sum=0;
        while(index>0) {
            sum +=BIT[index];
            index -=index & (-index);
        }
        return sum;
    }
};
