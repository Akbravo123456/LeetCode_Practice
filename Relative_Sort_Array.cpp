class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> freq;
        for(auto ab:arr1) freq[ab]++;

        vector<int> ans;
        for(auto ab:arr2){
            while(freq[ab]--){
                ans.push_back(ab);
            }
        }

        for(auto& [ab,f]:freq){
            while(f>0 && f--){
                ans.push_back(ab);
            }
        }
        return ans;
    }
};