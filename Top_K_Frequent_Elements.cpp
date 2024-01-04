class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<list<int>> bucket(nums.size()+1);
        unordered_map<int,int> frequencyMap;

        for(int n : nums){
            frequencyMap[n]=frequencyMap[n]+1;
        }

        for (auto& entry:frequencyMap){
            int key=entry.first;
            int frequency=entry.second;
            bucket[frequency].push_back(key);
        }

        vector<int> res;
        for (int pos =bucket.size() - 1; pos >= 0 && res.size() < k; --pos){
            if (!bucket[pos].empty()){
                for(int integer:bucket[pos]){
                    res.push_back(integer);
                    if (res.size()==k){
                        break;
                    }
                }
            }
        }
        return res;
    }
};