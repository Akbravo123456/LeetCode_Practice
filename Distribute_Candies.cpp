class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int count=1;
        for(int i=1;i<candyType.size();i++){
            if(count==candyType.size()/2)
            return count;
            if(candyType[i]>candyType[i-1])
            count++;
        }
        return count;
    }
};