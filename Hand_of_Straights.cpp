class Solution {
public:
    bool isNStraightHand(vector<int>& hand,int groupSize) {
        if(hand.size() % groupSize!= 0) 
            return false;
        unordered_map<int, int> count;
        for (int card:hand){
            count[card]++;
        }   
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(const auto& [card, _]:count) {
            minHeap.push(card);
        }
        while (!minHeap.empty()) {
            int start = minHeap.top();  
            for (int i = 0; i < groupSize; ++i) {
                int card = start + i;   
                if (count[card] == 0) {
                    return false;
                } 
                count[card]--;
                if (count[card] == 0 && card == minHeap.top()) {
                    minHeap.pop();
                }
            }
        }
        
        return true;
    }
};